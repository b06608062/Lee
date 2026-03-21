class Solution {
public:
  int numberOfSubmatrices(vector<vector<char>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> X(m + 1, vector<int>(n + 1, 0)),
        Y(m + 1, vector<int>(n + 1, 0));
    int res = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        X[i][j] = X[i - 1][j] + X[i][j - 1] - X[i - 1][j - 1];
        Y[i][j] = Y[i - 1][j] + Y[i][j - 1] - Y[i - 1][j - 1];
        char ch = grid[i - 1][j - 1];
        if (ch == 'X')
          X[i][j]++;
        else if (ch == 'Y')
          Y[i][j]++;
        if (X[i][j] && X[i][j] == Y[i][j])
          res++;
      }
    }
    return res;
  }
};