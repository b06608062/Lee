class Solution {
public:
  int maximumLengthSubstring(string s) {
    int n = s.size();

    vector<int> cnt(26, 0);

    int l = 0, r = 0, res = 0;
    while (r < n) {
      char ch = s[r];
      if (++cnt[ch - 'a'] >= 3) {
        while (s[l] != ch)
          cnt[s[l++] - 'a']--;
        cnt[s[l++] - 'a']--;
      }
      res = max(res, r - l + 1);
      r++;
    }

    return res;
  }
};