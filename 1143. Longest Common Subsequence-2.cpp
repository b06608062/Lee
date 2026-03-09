class Solution {
public:
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    if (m < n)
      return longestCommonSubsequence(text2, text1);
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= m; ++i) {
      int diag = 0;
      for (int j = 1; j <= n; ++j) {
        int up = f[j];
        if (text1[i - 1] == text2[j - 1])
          f[j] = diag + 1;
        else
          f[j] = max(f[j - 1], up);
        diag = up;
      }
    }
    return f[n];
  }
};
