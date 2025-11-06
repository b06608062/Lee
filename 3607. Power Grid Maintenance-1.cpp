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
    p[b] = a;
    sz[a] += sz[b];
    return true;
  }
};

class Solution {
public:
  vector<int> processQueries(int c, vector<vector<int>> &connections,
                             vector<vector<int>> &queries) {
    int n = c;
    DSU dsu(n + 1);

    for (auto &e : connections)
      dsu.unite(e[0], e[1]);

    unordered_map<int, set<int>> umap;
    for (int i = 1; i <= n; ++i)
      umap[dsu.find(i)].insert(i);

    vector<int> res;
    for (auto &q : queries) {
      int x = q[1];
      int rX = dsu.find(x);
      auto &sset = umap[rX];
      auto it = sset.find(x);
      if (q[0] == 1)
        if (it != sset.end())
          res.push_back(x);
        else
          res.push_back(sset.empty() ? -1 : *sset.begin());
      else if (it != sset.end())
        sset.erase(it);
    }

    return res;
  }
};