#ifndef _UTIL_H_
#define _UTIL_H_

#include <bits/stdc++.h>

using namespace std;

/**
 * Heap's algorithm to generate all permutations.
 *
 * @param f  a function accept one permutation and returning true to continue, false to stop
 */
template <typename T, typename F>
void foreach_permutation(T & xs, F f) {
  int n = xs.size();
  vector<int> c(n);
  if (!f(xs)) return;
  for (int i = 0; i < n; i++) {
    if (c[i] < i) {
      swap(xs[i & 1 ? c[i] : 0], xs[i]);
      if (!f(xs)) return;
      c[i]++;
      i = 0;
    } else c[i] = 0;
  }
}

template <typename T>
ostream & operator<<(ostream & out, const vector<T> & xs) {
  size_t n = xs.size();
  for (size_t i = 0; i < n; i++) {
    if (i != 0) out << " ";
    out << xs[i];
  }
  return out;
}

template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}

// Returns modulo inverse of a with respect to m using extended Euclid Algorithm
// Assumption: a and m are coprimes, i.e., gcd(a, m) = 1
template <typename T>
T modinv(T a, T m) {
  if (m == 1) return 0;
  T m0 = m, t, q;
  T x0 = 0, x1 = 1;
  while (a > 1) {
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = x0;
    x0 = x1 - q * x0;
    x1 = t;
  }
  if (x1 < 0) x1 += m0;
  return x1;
}

#endif
