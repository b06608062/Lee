class Solution {
public:
  vector<vector<int>> blocks;
  vector<vector<int>> guarded;
  vector<int> dirs{0, 1, 0, -1, 0};
  int m, n;
  int countUnguarded(int m, int n, vector<vector<int>> &guards,
                     vector<vector<int>> &walls) {
    blocks = vector<vector<int>>(m, vector<int>(n, 0));
    for (auto &g : guards)
      blocks[g[0]][g[1]] = 1;
    for (auto &w : walls)
      blocks[w[0]][w[1]] = 1;

    guarded = vector<vector<int>>(m, vector<int>(n, 0));
    this->m = m;
    this->n = n;

    for (auto &g : guards)
      for (int k = 0; k < 4; ++k)
        dfs(g[0] + dirs[k], g[1] + dirs[k + 1], k);

    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (!guarded[i][j] && !blocks[i][j])
          res++;

    return res;
  }

  void dfs(int i, int j, int dir) {
    if (i < 0 || i >= m || j < 0 || j >= n || blocks[i][j])
      return;
    guarded[i][j] = 1;
    dfs(i + dirs[dir], j + dirs[dir + 1], dir);
  }
};