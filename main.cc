#define NDEBUG

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;
using tii = tuple<int, int>;

#ifdef NDEBUG
#  define debug(...)
#else
#  include "debug.hh"
#endif

int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout << fixed;
  return 0;
}
