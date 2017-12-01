#ifndef _DISJOINT_SET_H_
#define _DISJOINT_SET_H_

class disjoint_set {
  size_t n;
  int * parents, * ranks;

public:

  disjoint_set(size_t n): n(n) {
    parents = new int[n];
    for (size_t i = 0; i < n; i++) parents[i] = i;
    ranks = new int[n]();
  }

  virtual ~disjoint_set() {
    if (parents) delete[] parents;
    if (ranks) delete[] ranks;
  }

  int find(int x) {
    if (parents[x] != x) parents[x] = find(parents[x]);
    return parents[x];
  }

  void merge(int x, int y) {
    int rx = find(x), ry = find(y);
    if (rx == ry) return;
    if      (ranks[rx] < ranks[ry]) parents[rx] = ry;
    else if (ranks[ry] < ranks[rx]) parents[ry] = rx;
    else {
      parents[ry] = rx;
      ranks[rx]++;
    }
  }
};

#endif /* _DISJOINT_SET_H_ */
