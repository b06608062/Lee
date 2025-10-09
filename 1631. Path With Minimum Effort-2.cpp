// binary search + dfs
class Solution {
public:
  int m, n;
  vector<int> dirs{0, 1, 0, -1, 0};
  int minimumEffortPath(vector<vector<int>> &heights) {
    m = heights.size(), n = heights[0].size();

    int maxH = 1;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        maxH = max(maxH, heights[i][j]);

    int l = 0, r = maxH - 1;
    while (l < r) {
      int limit = l + (r - l) / 2;
      vector<vector<int>> vis(m, vector<int>(n, 0));
      if (!dfs(heights, vis, limit, 0, 0))
        l = limit + 1;
      else
        r = limit;
    }

    return l;
  }

  bool dfs(vector<vector<int>> &heights, vector<vector<int>> &vis, int limit,
           int i, int j) {
    if (i == m - 1 && j == n - 1)
      return true;

    vis[i][j] = 1;
    int fromH = heights[i][j];
    for (int k = 0; k < 4; ++k) {
      int ni = i + dirs[k], nj = j + dirs[k + 1];
      if (ni < 0 || ni >= m || nj < 0 || nj >= n || vis[ni][nj] ||
          abs(fromH - heights[ni][nj]) > limit)
        continue;
      if (dfs(heights, vis, limit, ni, nj))
        return true;
    }

    return false;
  }
};