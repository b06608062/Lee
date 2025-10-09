struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a, sz[a] += sz[b];
    return true;
  }
};

class Solution {
public:
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();

    DSU dsu(n + 1);

    for (auto &e : edges)
      if (!dsu.unite(e[0], e[1]))
        return e;

    return {};
  }
};