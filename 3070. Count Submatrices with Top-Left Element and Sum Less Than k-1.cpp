class Solution {
public:
  int countSubmatrices(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> diff(m + 1, vector<int>(n + 1, 0));
    int res = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        diff[i][j] = diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1] +
                     grid[i - 1][j - 1];
        if (diff[i][j] <= k)
          res++;
      }
    }
    return res;
  }
};