class Solution {
public:
  vector<vector<int>> memo;
  int m, n;
  int uniquePaths(int m, int n) {
    this->m = m;
    this->n = n;
    memo.assign(m, vector<int>(n, -1));
    return dfs(m - 1, n - 1);
  }

  int dfs(int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n)
      return 0;
    if (i == 0 && j == 0)
      return 1;
    int &res = memo[i][j];
    if (res != -1)
      return res;
    return res = dfs(i - 1, j) + dfs(i, j - 1);
  }
};
