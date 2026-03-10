class Solution {
public:
  int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<vector<unsigned int>> f(m + 1, vector<unsigned int>(n + 1, 0));
    f[0][0] = 1;
    for (int i = 1; i <= m; ++i) {
      f[i][0] = 1;
      for (int j = 1; j <= n; ++j) {
        f[i][j] = f[i - 1][j];
        if (s[i - 1] == t[j - 1])
          f[i][j] += f[i - 1][j - 1];
      }
    }
    return f[m][n];
  }
};