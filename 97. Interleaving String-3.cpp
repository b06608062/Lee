class Solution {
public:
  vector<vector<int>> memo;
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size())
      return false;
    memo.assign(m, vector<int>(n, -1));
    return dfs(s1, s2, s3, m - 1, n - 1);
  }
  int dfs(string &s1, string &s2, string &s3, int i, int j) {
    if (i < 0 && j < 0)
      return 1;
    if (i < 0)
      return (s2[j] == s3[j]) && dfs(s1, s2, s3, i, j - 1);
    else if (j < 0)
      return (s1[i] == s3[i]) && dfs(s1, s2, s3, i - 1, j);
    int &res = memo[i][j];
    if (res != -1)
      return res;
    return res = ((s2[j] == s3[i + j + 1]) && dfs(s1, s2, s3, i, j - 1)) ||
                 ((s1[i] == s3[i + j + 1]) && dfs(s1, s2, s3, i - 1, j));
  }
};

class Solution {
public:
  vector<vector<int>> memo;
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size())
      return false;
    memo.assign(m + 1, vector<int>(n + 1, -1));
    return dfs(s1, s2, s3, m, n);
  }
  int dfs(string &s1, string &s2, string &s3, int i, int j) {
    if (i == 0 && j == 0)
      return 1;
    int &res = memo[i][j];
    if (res != -1)
      return res;
    if (i == 0)
      return res = (s2[j - 1] == s3[j - 1]) && dfs(s1, s2, s3, i, j - 1);
    else if (j == 0)
      return res = (s1[i - 1] == s3[i - 1]) && dfs(s1, s2, s3, i - 1, j);
    return res = ((s2[j - 1] == s3[i + j - 1]) && dfs(s1, s2, s3, i, j - 1)) ||
                 ((s1[i - 1] == s3[i + j - 1]) && dfs(s1, s2, s3, i - 1, j));
  }
};