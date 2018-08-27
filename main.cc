#pragma GCC diagnostic ignored "-Wunused-result"
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define NDEBUG

#include <algorithm>
#include <cassert>
#include <cinttypes>
#include <cstdio>
#include <vector>

#ifdef NDEBUG
#  define debug(...)
#else
#  define debug(...)                                \
  do {                                              \
    fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
    fprintf(stderr, __VA_ARGS__);                   \
    fputc('\n', stderr);                            \
  } while (false)
#endif

using namespace std;

int main() {
  return 0;
}
