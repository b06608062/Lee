// mark
// 1781
// 暴力枚舉 + 斜對角前綴和
class Solution {
public:
  int largestMagicSquare(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> rowPS(m, vector<int>(n + 1, 0));
    for (int r = 0; r < m; ++r) {
      int s = 0;
      for (int c = 0; c < n; ++c) {
        s += grid[r][c];
        rowPS[r][c + 1] = s;
      }
    }

    vector<vector<int>> colPS(m + 1, vector<int>(n, 0));
    for (int c = 0; c < n; ++c) {
      int s = 0;
      for (int r = 0; r < m; ++r) {
        s += grid[r][c];
        colPS[r + 1][c] = s;
      }
    }

    // diag1PS[r+1][c+1] = diag1PS[r][c] + grid[r][c]  (↘)
    vector<vector<int>> diag1PS(m + 1, vector<int>(n + 1, 0));
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        diag1PS[r + 1][c + 1] = diag1PS[r][c] + grid[r][c];
      }
    }

    // diag2PS[r+1][c] = diag2PS[r][c+1] + grid[r][c]  (↙)
    vector<vector<int>> diag2PS(m + 1, vector<int>(n + 1, 0));
    for (int r = 0; r < m; ++r) {
      for (int c = n - 1; c >= 0; --c) {
        diag2PS[r + 1][c] = diag2PS[r][c + 1] + grid[r][c];
      }
    }

    auto rowSum = [&](int r, int c, int k) -> int {
      return rowPS[r][c + k] - rowPS[r][c];
    };
    auto colSum = [&](int r, int c, int k) -> int {
      return colPS[r + k][c] - colPS[r][c];
    };
    auto diag1Sum = [&](int r, int c, int k) -> int {
      return diag1PS[r + k][c + k] - diag1PS[r][c];
    };
    auto diag2Sum = [&](int r, int c, int k) -> int {
      return diag2PS[r + k][c] - diag2PS[r][c + k];
    };

    int maxK = min(m, n);
    for (int k = maxK; k >= 2; --k) {
      for (int r = 0; r + k <= m; ++r) {
        for (int c = 0; c + k <= n; ++c) {
          int target = rowSum(r, c, k);

          // diags
          if (diag1Sum(r, c, k) != target)
            continue;
          if (diag2Sum(r, c, k) != target)
            continue;

          bool ok = true;

          //  rows
          for (int rr = r; rr < r + k; ++rr) {
            if (rowSum(rr, c, k) != target) {
              ok = false;
              break;
            }
          }
          if (!ok)
            continue;

          //  cols
          for (int cc = c; cc < c + k; ++cc) {
            if (colSum(r, cc, k) != target) {
              ok = false;
              break;
            }
          }
          if (ok)
            return k;
        }
      }
    }

    return 1;
  }
};
