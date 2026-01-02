class Solution {
public:
  int numMagicSquaresInside(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    int res = 0;
    for (int r = 0; r + 2 < m; ++r) {
      for (int c = 0; c + 2 < n; ++c) {
        if (grid[r + 1][c + 1] != 5)
          continue;
        bool vaild = true;
        unordered_set<int> uset;
        vector<int> row(3, 0), col(3, 0);
        int diag1 = 0, diag2 = 0;
        for (int i = 0; i < 3; ++i) {
          for (int j = 0; j < 3; ++j) {
            int x = grid[r + i][c + j];
            if (x < 1 || x > 9 || uset.count(x)) {
              vaild = false;
              break;
            }
            uset.insert(x);
            row[i] += x;
            col[j] += x;
            if (i == j)
              diag1 += x;
            if (i + j == 2)
              diag2 += x;
          }
        }
        for (int k = 0; k < 3; ++k)
          if (row[k] != 15 || col[k] != 15) {
            vaild = false;
            break;
          }
        if (!vaild || diag1 != 15 || diag2 != 15)
          continue;
        res++;
      }
    }

    return res;
  }
};