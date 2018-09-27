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
#  define debug(expr)
#else
#  define debug(expr) cerr << __FILE__ << ":" << __LINE__ << ": " << #expr << " = " << expr << endl
#endif

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}
