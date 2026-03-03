class Solution {
public:
  vector<string> generateParenthesis(int n) {
    if (n == 0)
      return {""};

    vector<vector<string>> dp(n + 1);
    dp[0] = {""};

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        // (A)B 結構：A 為 j 對，B 為 i-1-j 對
        for (string &a : dp[j]) {
          for (string &b : dp[i - 1 - j]) {
            dp[i].push_back("(" + a + ")" + b);
          }
        }
      }
    }
    return dp[n];
  }
};