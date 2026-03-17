struct DSU {
  vector<int> p, sz;
  int components;
  DSU(int n) : p(n), sz(n, 1), components(n) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    components--;
    return true;
  }
};

class Solution {
public:
  int minCost(int n, vector<vector<int>> &edges, int k) {
    int mx = 0;
    for (auto &e : edges)
      mx = max(mx, e[2]);
    int lo = 0, hi = mx + 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (!helper(n, edges, k, mid))
        lo = mid + 1;
      else
        hi = mid;
    }
    return lo;
  }

  bool helper(int n, vector<vector<int>> &edges, int k, int W) {
    DSU dsu(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1], w = e[2];
      if (w <= W)
        dsu.unite(u, v);
    }
    return dsu.components <= k;
  }
};