class Solution {
public:
  int maxSideLength(vector<vector<int>> &mat, int threshold) {
    // 2D Diff
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> diff(m + 1, vector<int>(n + 1, 0));
    int res = 0;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        int x = mat[i - 1][j - 1];
        diff[i][j] = diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1] + x;
        if (x <= threshold)
          res = 1;
      }
    }

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = res + 1; (i + k <= m) && (j + k <= n); ++k) {
          int ii = i + k, jj = j + k;
          if (diff[ii][jj] - diff[i + k][j] - diff[i][j + k] + diff[i][j] <=
              threshold)
            res = k;
          else
            break;
        }
      }
    }

    return res;
  }
};