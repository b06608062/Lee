class Solution {
public:
  bool validPalindrome(string s) {
    int n = s.size();

    for (int i = 0; i < n / 2; ++i) {
      int j = n - 1 - i;
      if (s[i] != s[j])
        return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
    }

    return true;
  }

  bool isPalindrome(string &s, int i, int j) {
    while (i < j)
      if (s[i++] != s[j--])
        return false;

    return true;
  }
};

class Solution {
public:
  int isValidPalindrome(string s, int k) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 2; i >= 0; --i)
      for (int j = i + 1; j < n; ++j)
        if (s[i] == s[j])
          dp[i][j] = dp[i + 1][j - 1];
        else
          dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);

    return dp[0][n - 1] <= k;
  }
};