#define NDEBUG

#include <algorithm>
#include <cassert>
#include <cinttypes>
#include <cstdio>

#ifdef NDEBUG
#  define pr(...)
#else
#  define pr(...)                                   \
  do {                                              \
    fprintf(stderr, "%s:%d: ", __FILE__, __LINE__); \
    fprintf(stderr, __VA_ARGS__);                   \
    putchar('\n');                                  \
  } while (false)
#endif

using namespace std;

int main() {
  return 0;
}
