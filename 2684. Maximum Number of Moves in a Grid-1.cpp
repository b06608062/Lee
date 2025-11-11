class Solution {
public:
  int maxMoves(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i)
      dp[i][0] = 1;

    int res = 0;
    for (int j = 1; j < n; ++j)
      for (int i = 0; i < m; ++i) {
        int x = grid[i][j];
        bool reach = false;
        if ((i > 0 && x > grid[i - 1][j - 1] && dp[i - 1][j - 1]) ||
            (x > grid[i][j - 1] && dp[i][j - 1]) ||
            (i < m - 1 && x > grid[i + 1][j - 1] && dp[i + 1][j - 1]))
          reach = true;
        dp[i][j] = reach;
        if (reach)
          res = max(res, j);
      }

    return res;
  }
};