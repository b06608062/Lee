struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return p[x] == x ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    return true;
  }
};

class Solution {
public:
  int countComponents(int n, vector<vector<int>> &edges) {
    DSU dsu(n);

    for (auto &e : edges)
      dsu.unite(e[0], e[1]);

    int res = 0;
    for (int i = 0; i < n; ++i)
      if (dsu.find(i) == i)
        res++;

    return res;
  }
};