class Solution {
public:
  int numSubmat(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();

    vector dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        dp[i][j] =
            dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];

    int res = 0;
    for (int i0 = 1; i0 <= m; ++i0)
      for (int j0 = 1; j0 <= n; ++j0)
        for (int i1 = i0; i1 <= m; ++i1)
          for (int j1 = j0; j1 <= n; ++j1) {
            int area = (i1 - i0 + 1) * (j1 - j0 + 1);
            if ((dp[i1][j1] - dp[i1][j0 - 1] - dp[i0 - 1][j1] +
                 dp[i0 - 1][j0 - 1]) == area)
              res++;
          }

    return res;
  }
};