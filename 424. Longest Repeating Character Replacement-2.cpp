class Solution {
public:
  int characterReplacement(string s, int k) {
    int n = s.size();

    res = 0;
    for (int c = 0; c < 26; ++c) {
      int l = 0, bad = 0;
      for (int r = 0; r < n; ++r) {
        bad += (s[r] - 'A' != c);
        while (bad > k) {
          bad -= (s[l] - 'A' != c);
          l++;
        }
        res = max(res, r - l + 1);
      }
    }

    return res;
  }
};
