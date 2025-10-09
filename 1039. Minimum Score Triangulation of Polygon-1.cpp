class Solution {
public:
  int minScoreTriangulation(vector<int> &values) {
    int n = values.size();

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));

    for (int i = 0; i < n - 1; ++i)
      dp[i][i + 1] = 0;

    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        int j = i + len - 1;
        int best = INT_MAX / 2;
        for (int k = i + 1; k < j; ++k)
          best = min(best,
                     dp[i][k] + dp[k][j] + values[i] * values[k] * values[j]);
        dp[i][j] = best;
      }
    }

    return dp[0][n - 1];
  }
};