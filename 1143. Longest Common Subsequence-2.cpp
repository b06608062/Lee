class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    if (text1.size() < text2.size())
      swap(text1, text2);
    int m = text1.size(), n = text2.size();

    vector<int> dp(n + 1, 0);

    for (int i = 1; i <= m; ++i) {
      int diag = dp[0];
      for (int j = 1; j <= n; ++j) {
        int up = dp[j];
        if (text1[i - 1] == text2[j - 1])
          dp[j] = diag + 1;
        else
          dp[j] = max(up, dp[j - 1]);
        diag = up;
      }
    }

    return dp[n];
  }
};