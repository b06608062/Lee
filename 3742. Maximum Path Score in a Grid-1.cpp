class Solution {
public:
  int maxPathScore(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();

    vector dp(m + 1, vector(n + 1, vector<int>(k + 1, -1))); // 恰好

    dp[1][1][0] = 0;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        if (i == 1 && j == 1)
          continue;
        int score = grid[i - 1][j - 1];
        int cost = score ? 1 : 0;
        for (int c = 0; c <= k; ++c)
          if (c + cost <= k) {
            if (dp[i - 1][j][c] != -1)
              dp[i][j][c + cost] = dp[i - 1][j][c] + score;
            if (dp[i][j - 1][c] != -1)
              dp[i][j][c + cost] =
                  max(dp[i][j][c + cost], dp[i][j - 1][c] + score);
          }
      }

    int res = -1;
    for (int c = 0; c <= k; ++c)
      res = max(res, dp[m][n][c]);

    return res;
  }
};