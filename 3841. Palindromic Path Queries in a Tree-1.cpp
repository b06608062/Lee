// mark
// ???
// LCA + 差分樹狀樹組 + 樹中路徑合法回文
// 2791 + 1483 + 3515 + 231

struct FenwickTree {
  vector<int> bit;
  FenwickTree(int n) : bit(n + 1, 0) {}

  void update(int i, int delta) {
    while (i < bit.size()) {
      bit[i] ^= delta;
      i += lowbit(i);
    }
  }

  int query(int i) {
    int sum = 0;
    while (i > 0) {
      sum ^= bit[i];
      i -= lowbit(i);
    }
    return sum;
  }

  int lowbit(int x) { return x & (-x); }
};

class Solution {
public:
  vector<int> depth;
  vector<vector<int>> g, up;

  vector<int> in, out;
  vector<int> path_xor_from_root;
  int clock = 0;
  vector<bool> palindromePath(int n, vector<vector<int>> &edges, string s,
                              vector<string> &queries) {
    int m = bit_width((unsigned)n);
    g.resize(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      g[u].push_back(v);
      g[v].push_back(u);
    }
    depth.resize(n);
    up.resize(n, vector<int>(m, -1));
    dfs1(0, -1);
    for (int j = 1; j < m; ++j)
      for (int i = 0; i < n; ++i)
        if (up[i][j - 1] != -1)
          up[i][j] = up[up[i][j - 1]][j - 1];

    FenwickTree ft(n);
    in.resize(n + 1), out.resize(n + 1);
    path_xor_from_root.resize(n);
    path_xor_from_root[0] = 1 << (s[0] - 'a');
    dfs2(s, 0, -1);

    vector<bool> res;
    string op;
    int u, v;
    char ch;
    for (auto &q : queries) {
      stringstream ss(q);
      ss >> op >> u;
      if (op[0] == 'u') {
        ss >> ch;
        int d = (1 << (s[u] - 'a')) ^ (1 << (ch - 'a'));
        s[u] = ch;
        ft.update(in[u], d);
        ft.update(out[u] + 1, d);
      } else {
        ss >> v;
        int lca = get_lca(u, v);
        int cur = path_xor_from_root[u] ^ path_xor_from_root[v] ^
                  ft.query(in[u]) ^ ft.query(in[v]) ^ (1 << (s[lca] - 'a'));
        res.push_back((cur & (cur - 1)) == 0);
      }
    }

    return res;
  }

  void dfs1(int u, int p) {
    up[u][0] = p;
    for (int v : g[u]) {
      if (v != p) {
        depth[v] = depth[u] + 1;
        dfs1(v, u);
      }
    }
  };

  int get_kth_ancestor(int node, int k) {
    for (; k; k &= k - 1)
      node = up[node][countr_zero((unsigned)k)];
    return node;
  }

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

  void dfs2(string &s, int u, int p) {
    in[u] = ++clock;
    for (auto v : g[u]) {
      if (v != p) {
        path_xor_from_root[v] = path_xor_from_root[u] ^ (1 << (s[v] - 'a'));
        dfs2(s, v, u);
      }
    }
    out[u] = clock;
  }
};
