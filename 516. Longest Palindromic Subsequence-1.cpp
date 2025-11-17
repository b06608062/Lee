class Solution {
public:
  vector<vector<int>> memo;
  int longestPalindromeSubseq(string s) {
    int n = s.size();
    string t = s;
    reverse(t.begin(), t.end());
    memo.assign(n, vector<int>(n, -1));

    return dfs(s, t, n - 1, n - 1);
  }

  int dfs(string &s, string &t, int i, int j) {
    if (i < 0 || j < 0)
      return 0;
    int &res = memo[i][j];
    if (res != -1)
      return res;
    if (s[i] == t[j])
      return res = dfs(s, t, i - 1, j - 1) + 1;
    else
      return res = max(dfs(s, t, i - 1, j), dfs(s, t, i, j - 1));
  }
};