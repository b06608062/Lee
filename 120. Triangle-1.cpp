class Solution {
public:
  int minimumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();

    vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));

    dp[0][0] = triangle[0][0];
    for (int r = 1; r < n; ++r)
      for (int i = 0; i <= r; ++i) {
        if (i - 1 >= 0)
          dp[r][i] = dp[r - 1][i - 1] + triangle[r][i];
        dp[r][i] = min(dp[r][i], dp[r - 1][i] + triangle[r][i]);
      }

    int res = INT_MAX / 2;
    for (auto x : dp[n - 1])
      res = min(res, x);

    return res;
  }
};