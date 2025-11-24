class Solution {
public:
  // lazy dp
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();

    vector<int> dirs{0, 1, 0, -1, 0};

    vector<vector<int>> f(n, vector<int>(n, n * n));
    f[0][0] = grid[0][0];

    for (int k = 0; k < n * n - 1; ++k) {
      bool updated = false;
      for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
          int vH = grid[i][j];
          for (int d = 0; d < 4; ++d) {
            int ui = i + dirs[d], uj = j + dirs[d + 1];
            if (ui < 0 || ui >= n || uj < 0 || uj >= n)
              continue;
            int h = max(f[ui][uj], vH);
            if (h < f[i][j]) {
              updated = true;
              f[i][j] = h;
            }
          }
        }
      if (!updated)
        break;
    }

    return f[n - 1][n - 1];
  }
};