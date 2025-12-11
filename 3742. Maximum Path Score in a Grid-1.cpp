// mark
// 1804
// 三維 DP + 限制成本 + 注意是否能合法轉移
// dp[i][j][c]: 前 i 行 j 列，使用成本 c 的最大路徑分數
// 注意合法起點只有左上角 (0,0)
class Solution {
public:
  int maxPathScore(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();

    vector dp(m + 1, vector(n + 1, vector<int>(k + 1, -1)));

    dp[1][1][0] = 0; // 恰好
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

    // 因為是恰好，所以要檢查所有 c ≤ k 的情況才會是至多 k
    int res = -1;
    for (int c = 0; c <= k; ++c)
      res = max(res, dp[m][n][c]);

    return res;
  }
};

class Solution {
public:
  int maxPathScore(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();

    vector dp(m + 1, vector(n + 1, vector<int>(k + 1, -1)));

    for (int c = 0; c <= k; ++c) // 至多
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

class Solution {
public:
  int maxPathScore(vector<vector<int>> &grid, int k) {
    const int inf = INT_MIN / 2;
    int m = grid.size(), n = grid[0].size();

    vector memo(m, vector(n, vector<int>(k + 1, -1))); // 至多

    auto dfs = [&](this auto &&dfs, int i, int j, int k) {
      if (i < 0 || j < 0 || k < 0)
        return inf;
      if (i == 0 && j == 0)
        return 0;
      if (memo[i][j][k] != -1)
        return memo[i][j][k];
      int x = grid[i][j];
      int nxtK = k - (x > 0 ? 1 : 0);
      return memo[i][j][k] = max(dfs(i - 1, j, nxtK), dfs(i, j - 1, nxtK)) + x;
    };

    int res = dfs(m - 1, n - 1, k);

    return res < 0 ? -1 : res;
  }
};