struct Edge {
  int w, u, v;
};

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
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();

    // min heap
    auto comp = [](auto &a, auto &b) { return a.w > b.w; };
    priority_queue<Edge, vector<Edge>, decltype(comp)> pq(comp);
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j)
        pq.push({abs(points[i][0] - points[j][0]) +
                     abs(points[i][1] - points[j][1]),
                 i, j});

    DSU dsu(n);

    int count = 0, res = 0;
    while (!pq.empty()) {
      auto [w, u, v] = pq.top();
      pq.pop();
      if (dsu.unite(u, v)) {
        res += w;
        if (++count == n - 1)
          break;
      }
    }

    return res;
  }
};