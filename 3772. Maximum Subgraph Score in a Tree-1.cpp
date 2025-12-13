// mark
// 2235
// 換根 DP 進階題
// sc[x] = 只在 x 的子樹內、且必須包含 x 的最佳連通子圖分數
// dp[x] = 在整棵樹中，所有「包含 x」的連通連通子圖的最大分數（即節點 x 的答案）
// dp[子] = sc[子] + max(dp[父] - max(sc[子], 0), 0)
class Solution {
public:
  vector<vector<int>> adj;
  vector<int> dp, sc, g;
  int n;
  vector<int> maxSubgraphScore(int n, vector<vector<int>> &edges,
                               vector<int> &good) {
    this->n = n;
    g = good;

    adj.resize(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dp.resize(n);
    sc.resize(n);

    dfs1(0);
    dp[0] = sc[0];
    dfs2(0);

    return dp;
  }

  void dfs1(int u, int p = -1) {
    for (auto v : adj[u]) {
      if (v == p)
        continue;
      dfs1(v, u);
      sc[u] += max(0, sc[v]);
    }
    sc[u] += g[u] == 1 ? 1 : -1;
  }

  void dfs2(int u, int p = -1) {
    for (auto v : adj[u]) {
      if (v == p)
        continue;
      dp[v] = sc[v] + max(dp[u] - max(sc[v], 0), 0);
      dfs2(v, u);
    }
  }
};