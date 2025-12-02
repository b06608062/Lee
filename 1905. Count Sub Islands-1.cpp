class Solution {
public:
  vector<int> dirs{0, 1, 0, -1, 0};
  int m, n;
  int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2) {
    m = grid1.size(), n = grid1[0].size();

    int res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (grid1[i][j] && grid2[i][j])
          if (dfs(grid1, grid2, i, j))
            res++;

    return res;
  }

  bool dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int i,
           int j) {
    if (i < 0 || i >= m || j < 0 || j >= n)
      return true;
    if (grid1[i][j] == 0 || grid2[i][j] == 0)
      return grid2[i][j] == 0;

    grid1[i][j] = 0;
    grid2[i][j] = 0;
    bool res = true;
    for (int d = 0; d < 4; ++d)
      res &= dfs(grid1, grid2, i + dirs[d], j + dirs[d + 1]);

    return res;
  }
};