#ifndef _SEGMENT_TREE_H_
#define _SEGMENT_TREE_H_

#include <ostream>
#include <stdexcept>
#include <vector>

class segment_tree {
  int n;
  std::vector<int> nodes;

  int build(const std::vector<int> & xs, int l, int r, int i) {
    if (l == r) {
      nodes[i] = xs[l];
    } else {
      int m = (l + r) / 2;
      nodes[i] = build(xs, l, m, 2*i+1) + build(xs, m+1, r, 2*i+2);
    }
    return nodes[i];
  }

  int query(int l, int r, int ql, int qr, int i) {
    if (ql <= l && r <= qr) return nodes[i];
    if (r < ql || qr < l) return 0;
    int m = (l + r) / 2;
    return query(l, m, ql, qr, 2*i+1) + query(m+1, r, ql, qr, 2*i+2);
  }

  void update(int l, int r, int i, int diff, int j) {
    if (i < l || r < i) return;
    nodes[j] += diff;
    if (l != r) {
      int m = (l + r) / 2;
      update(l, m, i, diff, 2*j+1);
      update(m+1, r, i, diff, 2*j+2);
    }
  }

public:

  segment_tree(const std::vector<int> & xs): n(xs.size()) {
    int x = ceil(log2(xs.size()));
    nodes.resize((1 << (x + 1)) - 1);
    build(xs, 0, n - 1, 0);
  }

  int query(int l, int r) {
    if (l < 0 || r >= n || l > r)
      throw std::invalid_argument("l = " + std::to_string(l) + ", r = " + std::to_string(r));
    return query(0, n-1, l, r, 0);
  }

  void update(int i, int diff) {
    if (i < 0 || i >= n) throw std::invalid_argument("i = " + std::to_string(i));
    update(0, n-1, i, diff, 0);
  }

  friend std::ostream & operator<<(std::ostream & out, const segment_tree & t);
};

std::ostream & operator<<(std::ostream & out, const segment_tree & t) {
  auto it = t.nodes.begin();
  int i = 0, n = 1;
  while (it != t.nodes.end()) {
    out << *it++;
    if (++i == n) {
      out << std::endl;
      i = 0, n *= 2;
    } else out << " ";
  }
  return out;
}

#endif /* _SEGMENT_TREE_H_ */
