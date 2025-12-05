// mark
// 2097
// Binary Search + BFS
class Solution {
public:
  vector<int> dirs{0, 1, 0, -1, 0};
  int n;
  int swimInWater(vector<vector<int>> &grid) {
    n = grid.size();

    int l = 0, r = n * n - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      if (!bfs(grid, m))
        l = m + 1;
      else
        r = m;
    }

    return l;
  }

  bool bfs(vector<vector<int>> &grid, int h) {
    if (grid[0][0] > h)
      return false;

    vector<vector<int>> vis(n, vector<int>(n, 0));
    queue<pair<int, int>> q; // i, j

    vis[0][0] = 1;
    q.push({0, 0});
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      if (i == n - 1 && j == n - 1)
        return true;
      for (int k = 0; k < 4; ++k) {
        int ni = i + dirs[k], nj = j + dirs[k + 1];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n || vis[ni][nj] ||
            grid[ni][nj] > h)
          continue;
        vis[ni][nj] = 1;
        q.push({ni, nj});
      }
    }

    return false;
  }
};