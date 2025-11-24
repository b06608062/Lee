class Solution {
public:
  vector<int> dirs{0, 1, 0, -1, 0};
  int n;
  int swimInWater(vector<vector<int>> &grid) {
    n = grid.size();

    int lo = 0, hi = n * n;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      vector<vector<bool>> vis(n, vector<bool>(n, false));
      if (!dfs(grid, vis, 0, 0, mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo;
  }

  bool dfs(vector<vector<int>> &grid, vector<vector<bool>> &vis, int i, int j,
           int h) {
    if (i < 0 || i >= n || j < 0 || j >= n || vis[i][j] || grid[i][j] > h)
      return false;
    vis[i][j] = true;
    if (i == n - 1 && j == n - 1)
      return true;
    for (int d = 0; d < 4; ++d)
      if (dfs(grid, vis, i + dirs[d], j + dirs[d + 1], h))
        return true;
    return false;
  }
};