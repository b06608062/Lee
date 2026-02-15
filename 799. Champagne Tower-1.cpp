// mark
// 1856
// DP 模擬題

class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> f(100, vector<double>(100, 0));
    f[0][0] = poured;
    for (int i = 1; i < 100; ++i) {
      for (int j = 0; j <= i; ++j) {
        if (j > 0 && f[i - 1][j - 1] >= 1.0)
          f[i][j] += (f[i - 1][j - 1] - 1.0) / 2.0;
        if (j < i && f[i - 1][j] >= 1.0)
          f[i][j] += (f[i - 1][j] - 1.0) / 2.0;
      }
    }

    return f[query_row][query_glass] >= 1.0 ? 1.0 : f[query_row][query_glass];
  }
};