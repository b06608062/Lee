class Solution {
public:
  vector<vector<string>> res;
  vector<string> subset;
  vector<vector<int>> dp;
  vector<vector<string>> partition(string s) {
    int n = s.size();

    dp = vector<vector<int>>(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; --i)
      for (int j = i; j < n; ++j)
        if (s[i] == s[j] && (j - i + 1 <= 3 || dp[i + 1][j - 1]))
          dp[i][j] = 1;

    // for (int len = 1; len <= n; ++len)
    //   for (int l = 0; l + len - 1 < n; ++l) {
    //     int r = l + len - 1;
    //     if (s[l] == s[r] && (len <= 3 || dp[l + 1][r - 1]))
    //       dp[l][r] = 1;
    //   }

    helper(s, 0);

    return res;
  }

  void helper(string &s, int start) {
    int n = s.size();
    if (start == n) {
      res.push_back(subset);
      return;
    }

    for (int i = start; i < n; ++i)
      if (dp[start][i]) {
        subset.push_back(s.substr(start, i - start + 1));
        helper(s, i + 1);
        subset.pop_back();
      }
  }
};