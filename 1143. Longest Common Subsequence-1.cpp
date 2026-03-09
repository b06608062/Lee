class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (text1[i - 1] == text2[j - 1])
          f[i][j] = f[i - 1][j - 1] + 1;
        else
          f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    return f[m][n];
  }
};

class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    vector<vector<int>> f(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (text1[i - 1] == text2[j - 1])
          f[i][j] = f[i - 1][j - 1] + 1;
        else
          f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    string res = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
      if (text1[i - 1] == text2[j - 1]) {
        res += text1[i - 1];
        i--;
        j--;
      } else if (f[i - 1][j] >= f[i][j - 1])
        i--;
      else
        j--;
    }
    reverse(res.begin(), res.end());
    cout << res << endl;

    return f[m][n];
  }
};
