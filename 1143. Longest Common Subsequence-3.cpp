class Solution {
public:
  vector<vector<int>> memo;
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.size(), n = text2.size();
    memo.assign(m, vector<int>(n, -1));
    return dfs(text1, text2, m - 1, n - 1);
  }

  int dfs(string &text1, string &text2, int i, int j) {
    if (i < 0 || j < 0)
      return 0;
    int &res = memo[i][j];
    if (res != -1)
      return res;
    if (text1[i] == text2[j])
      return res = dfs(text1, text2, i - 1, j - 1) + 1;
    return res = max(dfs(text1, text2, i - 1, j), dfs(text1, text2, i, j - 1));
  }
};
