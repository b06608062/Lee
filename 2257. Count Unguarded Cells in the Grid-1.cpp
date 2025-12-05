// mark
// 1709
// Line Sweep on Grid
class Solution {
public:
  vector<vector<bool>> guarded;
  vector<vector<bool>> block;
  vector<int> dirs{0, 1, 0, -1, 0};
  int m, n;
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    this->m = m;
    this->n = n;
    guarded.assign(m, vector<bool>(n, false));
    block.assign(m, vector<bool>(n, false));

    for (auto &g : guards)
      block[g[0]][g[1]] = true;
    for (auto &w : walls)
      block[w[0]][w[1]] = true;

    for (auto &g : guards)
      for (int d = 0; d < 4; ++d)
        dfs(g[0] + dirs[d], g[1] + dirs[d + 1], d);

    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (!guarded[i][j] && !block[i][j])
          res++;

    return res;
  }

  void dfs(int i, int j, int d) {
    if (i < 0 || i >= m || j < 0 || j >= n || block[i][j])
      return;
    guarded[i][j] = true;
    dfs(i + dirs[d], j + dirs[d + 1], d);
  }
};