// mark
// ???
// 類似換根 DP
class Solution {
public:
  const int INF = INT_MAX / 2;
  vector<vector<int>> adj;
  vector<vector<int>> dist;
  int res = 0;
  int specialNodes(int n, vector<vector<int>> &edges, int x, int y, int z) {
    adj.resize(n);
    dist.assign(n, {INF, INF, INF});

    dist[x][0] = 0;
    dist[y][1] = 0;
    dist[z][2] = 0;
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs1(0, -1);
    dfs2(0, -1);

    return res;
  }

  void dfs1(int u, int p) {
    for (auto v : adj[u]) {
      if (v == p)
        continue;
      dfs1(v, u);
      for (int i = 0; i < 3; ++i) {
        dist[u][i] = min(dist[u][i], dist[v][i] + 1);
      }
    }
  }

  void dfs2(int u, int p) {
    if (p != -1) {
      for (int i = 0; i < 3; ++i) {
        dist[u][i] = min(dist[u][i], dist[p][i] + 1);
      }
    }
    if (valid(dist[u]))
      res++;
    for (auto v : adj[u]) {
      if (v != p)
        dfs2(v, u);
    }
  }

  bool valid(vector<int> arr) {
    sort(arr.begin(), arr.end());
    long long a = arr[0], b = arr[1], c = arr[2];
    return (a * a + b * b) == (c * c);
  }
};