class Solution {
public:
  vector<vector<unsigned int>> memo;
  int m, n;
  int numDistinct(string s, string t) {
    m = s.size(), n = t.size();
    memo.assign(m + 1, vector<unsigned int>(n + 1, -1));

    return dfs(s, t, m, n);
  }
  unsigned int dfs(string &s, string &t, int i, int j) {
    if (j == 0)
      return 1;
    if (i == 0)
      return 0;
    unsigned int &res = memo[i][j];
    if (res != -1)
      return res;
    res = dfs(s, t, i - 1, j);
    if (s[i - 1] == t[j - 1])
      res += dfs(s, t, i - 1, j - 1);
    return res;
  }
};