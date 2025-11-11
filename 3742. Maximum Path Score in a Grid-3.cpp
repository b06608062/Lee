class Solution {
public:
  int maxPathScore(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();

    vector dp(m + 1, vector(n + 1, vector<int>(k + 1, -1))); // 至多
    for (int c = 0; c <= k; ++c)
      dp[1][1][c] = 0;

    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (i == 1 && j == 1)
          continue;
        int score = grid[i - 1][j - 1];
        int cost = score ? 1 : 0;
        for (int c = 0; c <= k; ++c) {
          if (c - cost >= 0) {
            if (dp[i - 1][j][c - cost] != -1)
              dp[i][j][c] = dp[i - 1][j][c - cost] + score;
            if (dp[i][j - 1][c - cost] != -1)
              dp[i][j][c] = max(dp[i][j][c], dp[i][j - 1][c - cost] + score);
          }
        }
      }
    }

    return dp[m][n][k];
  }
};