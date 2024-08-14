#include <stdio.h>

#include <concepts>
#include <functional>
#include <memory>

template <typename T>
concept Addable = requires(T a, T b) {
    {
        a + b
    } -> std::same_as<T>;  // "the expression "a + b" is a valid expression that
                           // will compile"
    {
        a - b
    } -> std::same_as<T>;  // "the expression "a + b" is a valid expression that
                           // will compile"
};

template <Addable T, size_t length>
class RollingSum {
   public:
    using Type = T;
    static constexpr size_t size = length;

    RollingSum(T start) { underlying.fill(start); }

    void feed(Type value) {
        Type oldest = underlying[write_head];
        sum = sum - oldest;
        sum = sum + value;
        underlying[write_head] = value;
        write_head++;
        if (write_head >= size) {
            write_head = 0;
        }
    }
    Type Sum() { return sum; }

    size_t write_head = 0;
    Type sum = {};
    std::array<Type, size> underlying;
};
template <typename T>
concept Arithmetic = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
    { a - b } -> std::same_as<T>;
    { a *b } -> std::same_as<T>;
    { a / b } -> std::same_as<T>;
};

template <Arithmetic T>
class LinearFitSample {
   public:
    LinearFitSample() : LinearFitSample(0, 0) {}
    LinearFitSample(T x, T y) : x(x), y(y), xx(x * x), xy(x * y) {}
    LinearFitSample(T x, T y, T xx, T xy) : x(x), y(y), xx(xx), xy(xy) {}

    LinearFitSample operator+(const LinearFitSample &o) const {
        return LinearFitSample{x + o.x, y + o.y, xx + o.xx, xy + o.xy};
    }
    LinearFitSample operator-(const LinearFitSample &o) const {
        return LinearFitSample{x - o.x, y - o.y, xx - o.xx, xy - o.xy};
    }

    T x, y, xx, xy;
};

static size_t add_count = 0;
static size_t sub_count = 0;
static size_t mul_count = 0;
static size_t div_count = 0;

template <Arithmetic T>
class Counted {
   public:
    Counted(T v) : v(v) {}
    Counted operator+(const Counted &o) const {
        add_count++;
        return v + o.v;
    };
    Counted operator-(const Counted &o) const {
        sub_count++;
        return v - o.v;
    };
    Counted operator*(const Counted &o) const {
        mul_count++;
        return v * o.v;
    };
    Counted operator/(const Counted &o) const {
        div_count++;
        return v / o.v;
    };
    T value() { return v; }

   private:
    T v = 0;
};

int main() {
    using T = Counted<int>;
    RollingSum<LinearFitSample<T>, 100> ri{LinearFitSample<T>{T{0}, T{0}}};
    for (int i = 1; i < 5; i++) {
        size_t a = add_count;
        size_t su = sub_count;
        size_t mu = mul_count;
        size_t d = div_count;
        
        const LinearFitSample<T> s{T{i}, T{i * 2 + 1}};

        ri.feed(s);
        size_t Ns = ri.size;
        T N = (int)Ns;

        LinearFitSample<T> E = ri.Sum();

        T denom = (N * E.xx - E.x * E.x);
        if (denom.value() == 0) {
            printf("Would have divided by 0\n");
            continue;
        }
        T m = (N * E.xy - E.x * E.y) / denom;
        T b = (E.y - m * E.x) / N;

        a = add_count - a;
        su = sub_count - su;
        mu = mul_count - mu;
        d = div_count - d;

        printf("dA: %zu\n", a);
        printf("dS: %zu\n", su);
        printf("dM: %zu\n", mu);
        printf("dD: %zu\n", d);

        printf("y=%dx + %d\n", m.value(), b.value());
    }
    printf("Adds: %zu\n", add_count);
    printf("Subs: %zu\n", sub_count);
    printf("Muls: %zu\n", mul_count);
    printf("Divs: %zu\n", div_count);
}
