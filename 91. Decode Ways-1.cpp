class Solution {
public:
  int numDecodings(string s) {
    int n = s.size();

    vector<int> dp(n, 0);

    dp[0] = s[0] == '0' ? 0 : 1;
    for (int i = 1; i < n; ++i) {
      int one = s[i] - '0';
      int two = stoi(s.substr(i - 1, 2));
      if (one > 0)
        dp[i] += dp[i - 1];
      if (two >= 10 && two <= 26)
        dp[i] += i > 1 ? dp[i - 2] : 1;
    }

    return dp[n - 1];
  }
};