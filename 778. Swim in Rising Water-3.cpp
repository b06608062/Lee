// mark
// 2097
// Kruskal 變形
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

struct Edge {
  int cost, u, v;
};

class Solution {
public:
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();

    DSU dsu(n * n);
    vector<Edge> edges;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        int u = i * n + j;
        int fromH = grid[i][j];
        if (i + 1 < n) {
          int v = (i + 1) * n + j;
          edges.push_back({max(fromH, grid[i + 1][j]), u, v});
        }
        if (j + 1 < n) {
          int v = i * n + (j + 1);
          edges.push_back({max(fromH, grid[i][j + 1]), u, v});
        }
      }

    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b) { return a.cost < b.cost; });

    for (auto [cost, u, v] : edges) {
      dsu.unite(u, v);
      if (dsu.find(0) == dsu.find(n * n - 1))
        return cost;
    }

    return -1;
  }
};
