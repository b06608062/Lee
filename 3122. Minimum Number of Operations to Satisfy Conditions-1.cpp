// mark
// 1905
// Coloring DP
// 無法用貪心
class Solution {
public:
  int minimumOperations(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    const int INF = m * n;
    vector<vector<int>> dp(n, vector<int>(10, INF));
    vector<vector<int>> cost(n, vector<int>(10));
    for (int j = 0; j < n; ++j) {
      vector<int> cnt(10, 0);
      for (int i = 0; i < m; ++i)
        cnt[grid[i][j]]++;
      for (int p = 0; p < 10; ++p)
        cost[j][p] = m - cnt[p];
    }

    dp[0] = cost[0];
    for (int j = 1; j < n; ++j)
      for (int p = 0; p < 10; ++p)
        for (int q = 0; q < 10; ++q)
          if (q != p)
            dp[j][p] = min(dp[j][p], dp[j - 1][q] + cost[j][p]);

    int res = INF;
    for (int p = 0; p < 10; ++p)
      res = min(res, dp[n - 1][p]);

    return res;
  }
};