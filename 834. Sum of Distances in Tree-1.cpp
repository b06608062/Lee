// mark
// 834
// 換根 DP 入門題
// https://www.youtube.com/watch?v=VQWGjcqSJ4k
// dp[子] = dp[父] - sz[子] + (n - sz[子])
class Solution {
public:
  vector<vector<int>> adj;
  vector<int> sz, dp;
  int n;
  vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
    this->n = n;

    adj.resize(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    sz.resize(n);
    dp.resize(n);

    dfs1(0);
    dfs2(0);

    return dp;
  }

  void dfs1(int u, int p = -1) {
    for (auto v : adj[u]) {
      if (v == p)
        continue;
      dfs1(v, u);
      sz[u] += sz[v];
      dp[u] += dp[v] + sz[v];
    }
    sz[u] += 1;
  }

  void dfs2(int u, int p = -1) {
    for (auto v : adj[u]) {
      if (v == p)
        continue;
      dp[v] = dp[u] - sz[v] + n - sz[v];
      dfs2(v, u);
    }
  }
};