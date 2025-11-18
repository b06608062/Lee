class Solution {
public:
  int shortestPathBinaryMatrix(vector<vector<int>> &grid) {
    int n = grid.size();
    if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
      return -1;

    vector vis(n, vector<int>(n, 0));
    using P = pair<int, int>;
    queue<P> q;

    vis[0][0] = 1;
    q.push({0, 0});
    int cur = 0;
    while (!q.empty()) {
      cur++;
      int sz = q.size();
      while (sz--) {
        auto [ui, uj] = q.front();
        q.pop();
        if (ui == n - 1 && uj == n - 1)
          return cur;
        for (int i = -1; i <= 1; i++)
          for (int j = -1; j <= 1; j++) {
            int vi = ui + i, vj = uj + j;
            if (vi >= 0 && vi < n && vj >= 0 && vj < n &&
                !(vi == ui && vj == uj) && !vis[vi][vj] && grid[vi][vj] == 0) {
              vis[vi][vj] = 1;
              q.push({vi, vj});
            }
          }
      }
    }

    return -1;
  }
};