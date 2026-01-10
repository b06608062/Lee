class Solution {
public:
  int minimumDeleteSum(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    int total = 0;
    for (auto ch : s1)
      total += ch;
    for (auto ch : s2)
      total += ch;

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        int best = 0;
        if (s1[i - 1] == s2[j - 1])
          best = dp[i - 1][j - 1] + (s1[i - 1] - '\0') * 2;
        else
          best = max(dp[i - 1][j], dp[i][j - 1]);
        dp[i][j] = best;
      }
    }

    return total - dp[m][n];
  }
};