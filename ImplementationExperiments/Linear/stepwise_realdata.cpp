#include <stdio.h>

#define DATAFILE "../Data/100hz.h"
#include DATAFILE

#include <concepts>
#include <functional>
#include <memory>

#ifndef WINSIZE
#error "define WINSIZE"
#endif

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

template <Arithmetic T> class LinearFitSample {
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

int main() {
  using T = double;

  RollingSum<LinearFitSample<double>, WINSIZE> ri{
      LinearFitSample<double>{0, 0}};
  for (long i = 0; i < num_packets; i++) {
    packet p = packets[i];
    // T alt =

    const LinearFitSample<T> s{p.t, p.press};

    ri.feed(s);
    size_t Ns = ri.size;
    T N = (T)Ns;

    LinearFitSample<T> E = ri.Sum();

    T denom = (N * E.xx - E.x * E.x);
    if (denom == 0) {
      //   printf("Would have divided by 0\n");
      continue;
    }
    T m = (N * E.xy - E.x * E.y) / denom;
    T b = (E.y - m * E.x) / N;

    printf("%f %f %f %f\n", p.t, p.press, m, b);
    // printf("y=%fx + %f\n", m, b);
  }
}
