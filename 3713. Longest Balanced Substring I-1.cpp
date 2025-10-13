class Solution {
public:
  int longestBalanced(string s) {
    int n = s.size();

    vector<vector<int>> pref(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; ++i) {
      pref[i] = pref[i - 1];
      pref[i][s[i - 1] - 'a']++;
    }

    auto helper = [&](int L) -> bool {
      for (int i = 0; i + L - 1 < n; ++i) {
        int j = i + L - 1;
        bool isVaild = true;
        int curFreq = 0;
        for (int ch = 0; ch < 26; ++ch) {
          int freq = pref[j + 1][ch] - pref[i][ch];
          if (freq != 0) {
            if (curFreq == 0) {
              curFreq = freq;
            } else {
              if (freq != curFreq) {
                isVaild = false;
                break;
              }
            }
          }
        }
        if (isVaild)
          return true;
      }
      return false;
    };

    for (int i = n; i >= 1; --i)
      if (helper(i))
        return i;

    return -1;
  }
};