#include <fmt/core.h>
#include <stdio.h>

#include <concepts>
#include <functional>
#include <memory>

template <typename T>
concept Addable = requires(T a, T b) {
  {
    a + b
  } -> std::same_as<T>; // "the expression "a + b" is a valid expression that
                        // will compile"
  {
    a - b
  } -> std::same_as<T>; // "the expression "a + b" is a valid expression that
                        // will compile"
};

template <Addable T, size_t length> class RollingSum {
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

template <Arithmetic T, size_t maxx = 0, size_t maxy = 0>
class LinearFitSample {
public:
  LinearFitSample() : LinearFitSample(0, 0) {}
  LinearFitSample(T x, T y)
      : x(x), y(y), xx(x * x), xy(x * y), xxx(x * x * x), xxy(x * x * y),
        xxxx(x * x * x * x) {}
  LinearFitSample(T x, T y, T xx, T xy, T xxx, T xxy, T xxxx)
      : x(x), y(y), xx(xx), xy(xy), xxx(xxx), xxy(xxy), xxxx(xxxx) {}

  LinearFitSample operator+(const LinearFitSample &o) const {
    return LinearFitSample{x + o.x,     y + o.y,     xx + o.xx,    xy + o.xy,
                           xxx + o.xxx, xxy + o.xxy, xxxx + o.xxxx};
  }
  LinearFitSample operator-(const LinearFitSample &o) const {
    return LinearFitSample{x - o.x,     y - o.y,     xx - o.xx,    xy - o.xy,
                           xxx - o.xxx, xxy - o.xxy, xxxx - o.xxxx};
  }

  T x, y, xx, xy, xxx, xxy, xxxx;
};

static size_t add_count = 0;
static size_t sub_count = 0;
static size_t mul_count = 0;
static size_t div_count = 0;

template <Arithmetic T> class Counted {
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

double a = 10;
double b = 1;
double c = 1;

double f(double x) { return c + b * x + a * x * x; }

int main() {
  using S = double;
  using T = Counted<S>;
  RollingSum<LinearFitSample<T>, 8> ri{LinearFitSample<T>{T{0}, T{0}}};
  for (double t = 1; t < 250; t++) {
    size_t ad = add_count;
    size_t su = sub_count;
    size_t mu = mul_count;
    size_t d = div_count;

    const LinearFitSample<T> s{T{(S)t}, T{(S)f(t)}};

    ri.feed(s);
    size_t Ns = ri.size;
    T N = (S)Ns;

    LinearFitSample<T> E = ri.Sum();

    T delta = E.xxxx * (N * E.xx - E.x * E.x) -
              E.xxx * (N * E.xxx - E.xx * E.x) +
              E.xx * (E.xxx * E.x - E.xx * E.xx);
    if (delta.value() == 0) {
      printf("Would have divided by 0\n");
      continue;
    }
    T a = E.xxy * (N * E.xx - E.x * E.x) - E.xxx * (N * E.xy - E.x * E.y) +
          E.xx * (E.x * E.xy - E.xx * E.y);
    a = a / delta;
    T b = E.xxxx * (N * E.xy - E.x * E.y) - E.xxy * (N * E.xxx - E.xx * E.x) +
          E.xx * (E.xxx * E.y - E.xx * E.xy);
    b = b / delta;
    T c = E.xxxx * (E.xx * E.y - E.xy * E.x) -
          E.xxx * (E.xxx * E.y - E.xy * E.xx) +
          E.xxy * (E.xxx * E.x - E.xx * E.xx);
    c = c / delta;

    ad = add_count - ad;
    su = sub_count - su;
    mu = mul_count - mu;
    d = div_count - d;

    S val = f(t);
    S pval = a.value() * t * t + b.value() * t + c.value();
    S it = t;
    // printf("%lld, %lld, %lld, %lld, %lld, %lld, %lld    %lld, %lld, %lld,
    // %lld, %lld, %lld\n",
    //    E.x.value(), E.y.value(), E.xx.value(), E.xy.value(),
    //    E.xxx.value(), E.xxy.value(), E.xxxx.value(), a.value(),
    //    b.value(), c.value(), it, val, pval);
    fmt::println("{}, {}, {}, {}, {}, {}, {},    {}, {}, {}     {}, {}, {}",
                 E.x.value(), E.y.value(), E.xx.value(), E.xy.value(),
                 E.xxx.value(), E.xxy.value(), E.xxxx.value(), a.value(),
                 b.value(), c.value(), it, val, pval);
  }
  printf("Adds: %zu\n", add_count);
  printf("Subs: %zu\n", sub_count);
  printf("Muls: %zu\n", mul_count);
  printf("Divs: %zu\n", div_count);
  printf("%zu\n", sizeof(long long int));
}
