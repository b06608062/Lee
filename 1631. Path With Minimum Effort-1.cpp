// binary search + bfs
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
      if (!bfs(heights, limit))
        l = limit + 1;
      else
        r = limit;
    }

    return l;
  }

  bool bfs(vector<vector<int>> &heights, int limit) {
    queue<pair<int, int>> q;
    vector<vector<int>> vis(m, vector<int>(n, 0));

    vis[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      if (i == m - 1 && j == n - 1)
        return true;
      int fromH = heights[i][j];
      for (int k = 0; k < 4; ++k) {
        int ni = i + dirs[k], nj = j + dirs[k + 1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n || vis[ni][nj] ||
            abs(fromH - heights[ni][nj]) > limit)
          continue;
        vis[ni][nj] = 1;
        q.push({ni, nj});
      }
    }

    return false;
  }
};