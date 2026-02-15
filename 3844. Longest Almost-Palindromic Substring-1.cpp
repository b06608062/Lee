// MLE
// mark
// ???

class Solution {
public:
  int almostPalindromic(string s) {
    int n = s.size();
    vector f(n, vector(n, vector<bool>(2, false)));
    for (int i = 0; i < n; ++i) {
      f[i][i][0] = f[i][i][1] = true;
      if (i < n - 1) {
        if (s[i] == s[i + 1])
          f[i][i + 1][0] = true;
        f[i][i + 1][1] = true;
      }
    }

    int res = 2;
    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 2; j < n; ++j) {
        if (s[i] == s[j]) {
          if (f[i + 1][j - 1][0])
            f[i][j][0] = true;
          if (f[i + 1][j - 1][1])
            f[i][j][1] = true;
        }
        if (f[i + 1][j][0] || f[i][j - 1][0])
          f[i][j][1] = true;
        if (f[i][j][1])
          res = max(res, j - i + 1);
      }
    }

    return res;
  }
};