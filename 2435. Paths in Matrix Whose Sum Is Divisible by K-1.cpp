// mark
// 1952
// 三維 DP + MOD 狀態壓縮
class Solution {
public:
  int numberOfPaths(vector<vector<int>> &grid, int k) {
    const int MOD = 1e9 + 7;
    int m = grid.size(), n = grid[0].size();
    vector dp(m + 1, vector(n + 1, vector<int>(k, 0)));
    dp[0][1][0] = 1;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j) {
        int x = grid[i - 1][j - 1];
        for (int pk = 0; pk < k; ++pk) {
          int nk = (pk + x) % k;
          dp[i][j][nk] += dp[i - 1][j][pk];
          dp[i][j][nk] %= MOD;
          dp[i][j][nk] += dp[i][j - 1][pk];
          dp[i][j][nk] %= MOD;
        }
      }

    return dp[m][n][0];
  }
};