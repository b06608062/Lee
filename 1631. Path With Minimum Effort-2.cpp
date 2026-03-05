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
      if (!dfs(heights, vis, limit, 0, 0, heights[0][0]))
        l = limit + 1;
      else
        r = limit;
    }

    return l;
  }

  bool dfs(vector<vector<int>> &heights, vector<vector<int>> &vis, int limit,
           int i, int j, int fromH) {
    if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] ||
        abs(fromH - heights[i][j]) > limit)
      return false;
    if (i == m - 1 && j == n - 1)
      return true;

    vis[i][j] = 1;
    int curH = heights[i][j];
    for (int k = 0; k < 4; ++k) {
      int ni = i + dirs[k], nj = j + dirs[k + 1];
      if (dfs(heights, vis, limit, ni, nj, curH))
        return true;
    }

    return false;
  }
};

class Solution {
public:
  vector<int> dirs{0, 1, 0, -1, 0};
  int m, n;
  int minimumEffortPath(vector<vector<int>> &heights) {
    m = heights.size(), n = heights[0].size();
    int mx = 0;
    for (auto &row : heights)
      for (auto c : row)
        max(mx, c);

    int l = 1, r = mx - 1;
    while (l < r) {
      int mid = l + (r - l) / 2;
      vector<vector<bool>> vis(m, vector<bool>(n, false));
      if (!dfs(heights, vis, 0, 0, mid))
        l = mid + 1;
      else
        r = mid;
    }
    return l;
  }

  bool dfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, int i,
           int j, int limit) {
    if (i == m - 1 && j == n - 1)
      return true;
    int h = heights[i][j];
    vis[i][j] = true;
    for (int d = 0; d < 4; ++d) {
      int n_i = i + dirs[d], n_j = j + dirs[d + 1];
      if (n_i < 0 || n_i >= m || n_j < 0 || n_j >= n || vis[i][j] ||
          abs(heights[n_i][n_j] - h) > limit)
        continue;
      if (dfs(heights, vis, n_i, n_j, limit))
        return true;
    }
    return false;
  }
};
