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

#endif
