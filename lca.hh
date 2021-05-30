#pragma once

template <typename T, typename Adj>
struct LCA {

  LCA(T n, T root, Adj adj)
    : adj_(std::move(adj))
    , tin_(n+1), tout_(n+1)
    , log_(ceil(log2(n)))
    , up_(log_+1, std::vector<T>(n+1)) {
    Dfs(root, root);
  }

  T Get(T u, T v) const {
    if (IsAncestor(u, v)) return u;
    if (IsAncestor(v, u)) return v;
    for (int i = log_; i >= 0; --i) {
      if (!IsAncestor(up_[i][u], v)) u = up_[i][u];
    }
    return up_[0][u];
  }

private:
  Adj adj_;
  std::vector<T> tin_, tout_;
  int log_;
  std::vector<std::vector<T>> up_;
  T timer_{};

  void Dfs(T i, T p) {
    tin_[i] = ++timer_;
    up_[0][i] = p;
    for (int j = 1; j <= log_; ++j) {
      up_[j][i] = up_[j-1][up_[j-1][i]];
    }
    adj_(i, [this, p](T i, T j) { if (j != p) Dfs(j, i); });
    tout_[i] = ++timer_;
  }

  bool IsAncestor(T u, T v) const {
    return tin_[u] <= tin_[v] && tout_[v] <= tout_[u];
  }
};

template <typename T, typename Adj>
LCA<T, Adj> MakeLCA(T n, T root, Adj adj) {
  return LCA<T, Adj>(n, root, std::move(adj));
}
