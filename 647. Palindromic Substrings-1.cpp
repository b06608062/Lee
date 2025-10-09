class Solution {
public:
  int countSubstrings(string s) {
    int n = s.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    int res = 0;
    for (int len = 1; len <= n; ++len)
      for (int l = 0; l + len - 1 < n; ++l) {
        int r = l + len - 1;
        if (s[l] == s[r] && (len <= 2 || dp[l + 1][r - 1])) {
          dp[l][r] = 1;
          res++;
        }
      }

    return res;
  }
};