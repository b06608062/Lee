// mark
// 三維 0/1 背包 + 字串處理
class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    int len = strs.size();
    vector dp(m + 1, vector(n + 1, vector<int>(len + 1, 0)));

    for (int k = 1; k <= len; ++k) {
      auto &str = strs[k - 1];
      int zeros = 0, ones = 0;
      for (auto ch : str)
        if (ch == '0')
          zeros++;
        else
          ones++;
      for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j)
          if (i >= zeros && j >= ones)
            dp[i][j][k] =
                max(dp[i][j][k - 1], dp[i - zeros][j - ones][k - 1] + 1);
          else
            dp[i][j][k] = dp[i][j][k - 1];
    }

    return dp[m][n][len];
  }
};