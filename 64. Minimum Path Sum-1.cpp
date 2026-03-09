class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> f(m, vector<int>(n, INT_MAX / 2));

    f[0][0] = grid[0][0];
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (i > 0)
          f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
        if (j > 0)
          f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
      }

    return f[m - 1][n - 1];
  }
};

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> f(m + 1, vector<int>(n + 1, INT_MAX / 2));
    f[0][1] = 0;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        f[i][j] = grid[i - 1][j - 1] + min(f[i - 1][j], f[i][j - 1]);
    return f[m][n];
  }
};

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 1; i < m; ++i)
      grid[i][0] += grid[i - 1][0];
    for (int j = 1; j < n; ++j)
      grid[0][j] += grid[0][j - 1];
    for (int i = 1; i < m; ++i)
      for (int j = 1; j < n; ++j)
        grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);

    return grid[m - 1][n - 1];
  }
};

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0)
          continue;
        if (i == 0)
          grid[i][j] += grid[i][j - 1];
        else if (j == 0)
          grid[i][j] += grid[i - 1][j];
        else
          grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
      }
    return grid[m - 1][n - 1];
  }
};

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0)
          continue;
        int x = grid[i][j];
        grid[i][j] = INT_MAX / 2;
        if (i > 0)
          grid[i][j] = grid[i - 1][j] + x;
        if (j > 0)
          grid[i][j] = min(grid[i][j], grid[i][j - 1] + x);
      }
    return grid[m - 1][n - 1];
  }
};

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> f(n, INT_MAX / 2);
    f[0] = 0;
    for (int i = 0; i < m; ++i) {
      f[0] += grid[i][0];
      for (int j = 1; j < n; ++j)
        f[j] = min(f[j], f[j - 1]) + grid[i][j];
    }

    return f[n - 1];
  }
};

class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<int> f(n);
    f[0] = grid[0][0];
    for (int j = 1; j < n; ++j)
      f[j] = f[j - 1] + grid[0][j];

    for (int i = 1; i < m; ++i) {
      f[0] += grid[i][0];
      for (int j = 1; j < n; ++j)
        f[j] = min(f[j], f[j - 1]) + grid[i][j];
    }
    return f[n - 1];
  }
};

// 改問 Minimax Path (路徑最大值的最小值)
class Solution {
public:
  int minPathSum(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> f(m + 1, vector<int>(n + 1, INT_MAX));
    f[0][1] = 0;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        f[i][j] = max(grid[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1]));
    return f[m][n];
  }
};