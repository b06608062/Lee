class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1])
      return -1;

    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1;

    int res = 0;
    while (!q.empty()) {
      res++;
      int sz = q.size();
      while (sz--) {
        auto [ui, uj] = q.front();
        q.pop();
        if (ui == n - 1 && uj == n - 1)
          return res;
        for (int i = -1; i <= 1; ++i) {
          for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0)
              continue;
            int vi = ui + i, vj = uj + j;
            if (vi < 0 || vi >= n || vj < 0 || vj >= n || grid[vi][vj])
              continue;
            grid[vi][vj] = 1;
            q.push({vi, vj});
          }
        }
      }
    }

    return -1;
  }
};