class Solution {
public:
  int n;
  string longestPalindrome(string s) {
    n = s.size();
    int mx_l = 0, start = 0;
    for (int i = 0; i < n; ++i) {
      int l = max(slove(s, i, i), slove(s, i, i + 1));
      if (l > mx_l) {
        mx_l = l;
        start = i - (l - 1) / 2;
      }
    }

    return s.substr(start, mx_l);
  }
  int slove(string &s, int l, int r) {
    while (l >= 0 && r < n && s[l] == s[r])
      l--, r++;
    return r - l - 1;
  }
};
