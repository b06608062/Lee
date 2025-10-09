class Solution {
public:
  vector<vector<string>> res;
  vector<string> subset;
  vector<vector<int>> dp;
  vector<vector<string>> partition(string s) {
    int n = s.size();

    dp = vector<vector<int>>(n, vector<int>(n, 0));

    // for (int i = 0; i < n; ++i)
    //   for (int j = 0; j <= i; ++j)
    //     if (s[i] == s[j] && (i - j <= 2 || dp[j + 1][i - 1]))
    //       dp[j][i] = 1;

    for (int len = 1; len <= n; ++len)
      for (int l = 0; l + len - 1 < n; ++l) {
        int r = l + len - 1;
        if (s[l] == s[r] && (len <= 2 || dp[l + 1][r - 1]))
          dp[l][r] = 1;
      }

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