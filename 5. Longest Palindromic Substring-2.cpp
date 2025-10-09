class Solution {
public:
  int n;
  string longestPalindrome(string s) {
    n = s.size();

    int start = 0, len = 0;
    for (int i = 0; i < n; ++i) {
      int cur = max(helper(s, i, i), helper(s, i, i + 1));
      if (cur > len) {
        len = cur;
        start = i - (len - 1) / 2;
      }
    }

    return s.substr(start, len);
  }

  int helper(string &s, int l, int r) {
    while (l >= 0 && r < n && s[l] == s[r])
      l--, r++;

    return r - l - 1;
  }
};