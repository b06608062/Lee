class Solution {
public:
  int n, res;
  int countSubstrings(string s) {
    n = s.size();

    res = 0;
    for (int i = 0; i < n; ++i) {
      helper(s, i, i);
      helper(s, i, i + 1);
    }

    return res;
  }

  void helper(string &s, int l, int r) {
    while (l >= 0 && r < n && s[l] == s[r]) {
      res++;
      l--;
      r++;
    }
  }
};