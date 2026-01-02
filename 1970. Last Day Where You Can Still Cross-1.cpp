class Solution {
public:
  vector<int> dirs{0, 1, 0, -1, 0};
  unordered_map<int, int> umap;
  int m, n;
  int latestDayToCross(int row, int col, vector<vector<int>> &cells) {
    m = row, n = col;
    int d = cells.size();

    for (int i = 0; i < d; ++i) {
      int r = cells[i][0] - 1, c = cells[i][1] - 1;
      umap[r * n + c] = i + 1;
    }

    int l = 1, r = d;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (bfs(mid))
        l = mid + 1;
      else
        r = mid;
    }

    return l - 1;
  }

  bool bfs(int d) {
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    queue<pair<int, int>> q;
    for (int j = 0; j < n; ++j)
      if (umap[j] > d) {
        q.push({0, j});
        vis[0][j] = true;
      }

    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      for (int k = 0; k < 4; ++k) {
        int ni = i + dirs[k], nj = j + dirs[k + 1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n || vis[ni][nj] ||
            umap[ni * n + nj] <= d)
          continue;
        vis[ni][nj] = true;
        if (ni == m - 1)
          return true;
        q.push({ni, nj});
      }
    }

    return false;
  }
};