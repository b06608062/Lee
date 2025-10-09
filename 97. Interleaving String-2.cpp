class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() < s2.size())
      swap(s1, s2);
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size())
      return false;

    vector<bool> dp(n + 1, false);

    dp[0] = true;
    for (int j = 1; j <= n; ++j) {
      if (s2[j - 1] != s3[j - 1])
        break;
      dp[j] = true;
    }

    for (int i = 1; i <= m; ++i) {
      dp[0] = (s1[i - 1] == s3[i - 1] && dp[0]);
      for (int j = 1; j <= n; ++j)
        dp[j] = (s1[i - 1] == s3[i + j - 1] && dp[j]) ||
                (s2[j - 1] == s3[i + j - 1] && dp[j - 1]);
    }

    return dp[n];
  }
};