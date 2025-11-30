class Solution {
public:
  int minimumOperations(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    const int INF = m * n;
    vector<vector<int>> dp(n, vector<int>(10, INF));
    vector<vector<int>> cost(n, vector<int>(10));
    for (int i = 0; i < n; ++i) {
      vector<int> cnt(10, 0);
      for (int j = 0; j < m; ++j)
        cnt[grid[j][i]]++;
      for (int p = 0; p < 10; ++p)
        cost[i][p] = m - cnt[p];
    }

    dp[0] = cost[0];
    for (int i = 1; i < n; ++i)
      for (int p = 0; p < 10; ++p)
        for (int q = 0; q < 10; ++q)
          if (q != p)
            dp[i][p] = min(dp[i][p], dp[i - 1][q] + cost[i][p]);

    int res = INF;
    for (int p = 0; p < 10; ++p)
      res = min(res, dp[n - 1][p]);

    return res;
  }
};