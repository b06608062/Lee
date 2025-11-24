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
  int m, n;
  vector<vector<int>>
  findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
    m = edges.size();
    this->n = n;
    for (int i = 0; i < m; ++i)
      edges[i].push_back(i);
    sort(edges.begin(), edges.end(),
         [](auto &a, auto &b) { return a[2] < b[2]; });

    int MST = helper(edges);
    vector<vector<int>> res(2);
    for (int i = 0; i < m; ++i)
      if (helper(edges, -1, i) != MST)
        res[0].push_back(edges[i][3]);
      else if (helper(edges, i, -1) == MST)
        res[1].push_back(edges[i][3]);

    return res;
  }

  int helper(vector<vector<int>> &edges, int in = -1, int ex = -1) {
    DSU dsu(n);
    int cost = 0, cnt = 0;
    if (in != -1) {
      dsu.unite(edges[in][0], edges[in][1]);
      cost += edges[in][2];
      cnt++;
    }

    for (int i = 0; i < m; ++i) {
      if (i == ex)
        continue;
      if (dsu.unite(edges[i][0], edges[i][1])) {
        cost += edges[i][2];
        cnt++;
        if (cnt == n - 1)
          break;
      }
    }

    return cnt == n - 1 ? cost : INT_MAX;
  }
};