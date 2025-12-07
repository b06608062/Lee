// mark
// 1769
// DSU + 完全圖判斷
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
  int countCompleteComponents(int n, vector<vector<int>> &edges) {
    unordered_map<int, unordered_set<int>> adj;

    DSU dsu(n);

    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].insert(v);
      adj[v].insert(u);
      dsu.unite(u, v);
    }

    vector<int> edgeCount(n, 0);
    for (auto &e : edges)
      edgeCount[dsu.find(e[0])]++;

    vector<int> nodeCount(n, 0);
    for (int i = 0; i < n; ++i)
      nodeCount[dsu.find(i)]++;

    int res = 0;
    for (int i = 0; i < n; ++i)
      if (dsu.find(i) == i)
        if (nodeCount[i] * (nodeCount[i] - 1) / 2 == edgeCount[i])
          res++;

    return res;
  }
};