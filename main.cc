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

template <typename A>
ostream & operator<<(ostream & out, vector<A> xs) {
  out << "{";
  for (size_t i = 0; i < xs.size(); i++) {
    if (i > 0) out << ", ";
    out << xs[i];
  }
  out << "}";
  return out;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  return 0;
}
