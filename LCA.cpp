// 樹上倍增法 (Binary Lifting) + LCA + 位元運算優化 (C++20)
// 1. 預處理 up[i][j]：節點 i 的第 2^j 個祖先，狀態轉移 up[i][j] =
// up[up[i][j-1]][j-1]
// 2. 查詢 Kth Ancestor：利用 k 的二進位拆解 (k &= k-1)，跳躍 O(log k) 次
// 3. 查詢 LCA：先對齊深度
// (get_kth_ancestor)，再同步倍增上跳至最近公共祖先的子節點

class TreeAncestor {
public:
  vector<int> depth;
  vector<vector<int>> g, up;
  TreeAncestor(vector<pair<int, int>> &edges) {
    int n = edges.size() + 1;
    int m = bit_width((unsigned)n);

    g.resize(n);
    for (auto &[u, v] : edges) {
      g[u].push_back(v);
      g[v].push_back(u);
    }

    depth.resize(n);
    up.resize(n, vector<int>(m, -1));
    dfs(0, -1);

    for (int j = 1; j < m; ++j)
      for (int i = 0; i < n; ++i)
        if (up[i][j - 1] != -1)
          up[i][j] = up[up[i][j - 1]][j - 1];
  }

  int get_kth_ancestor(int node, int k) {
    for (; k; k &= k - 1)
      node = up[node][countr_zero((unsigned)k)];
    return node;
  }

  void dfs(int u, int p) {
    up[u][0] = p;
    for (int v : g[u]) {
      if (v != p) {
        depth[v] = depth[u] + 1;
        dfs(v, u);
      }
    }
  };

  int get_lca(int u, int v) {
    if (depth[u] > depth[v])
      swap(u, v);
    v = get_kth_ancestor(v, depth[v] - depth[u]);
    if (v == u)
      return u;
    for (int i = up[u].size() - 1; i >= 0; --i) {
      int px = up[u][i], py = up[v][i];
      if (px != py) {
        u = px;
        v = py;
      }
    }
    return up[u][0];
  }
};
