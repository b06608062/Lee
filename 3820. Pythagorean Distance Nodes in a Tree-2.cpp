// mark
// ???
// DFS 三次求距離
// 求全部點到三個特定點的距離 = 求三個特定點到全部點的距離
class Solution {
public:
  vector<vector<int>> adj;
  vector<vector<int>> dist;
  int specialNodes(int n, vector<vector<int>> &edges, int x, int y, int z) {
    adj.resize(n);
    dist.assign(3, vector<int>(n, 0));
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs(0, x, -1);
    dfs(1, y, -1);
    dfs(2, z, -1);

    int res = 0;
    for (int i = 0; i < n; ++i) {
      vector<long long> arr = {dist[0][i], dist[1][i], dist[2][i]};
      sort(arr.begin(), arr.end());
      if (arr[0] * arr[0] + arr[1] * arr[1] == arr[2] * arr[2]) {
        res++;
      }
    }
    return res;
  }

  void dfs(int i, int u, int p) {
    if (p != -1)
      dist[i][u] = dist[i][p] + 1;
    for (auto v : adj[u]) {
      if (v == p)
        continue;
      dfs(i, v, u);
    }
  }
};