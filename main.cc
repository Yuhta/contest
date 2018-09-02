#pragma GCC diagnostic ignored "-Wunused-result"
#define NDEBUG

#include <algorithm>
#include <cassert>
#include <cinttypes>
#include <cstdio>
#include <tuple>
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
