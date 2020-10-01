#define NDEBUG

#ifdef NDEBUG
#  define DEBUG(...)
#else
#  include "debug.hh"
#endif

#include <bits/stdc++.h>

using namespace std;

__attribute__((constructor)) void Init() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout << fixed;
}

int main() {
  return 0;
}
