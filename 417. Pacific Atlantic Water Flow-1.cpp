// mark
// 逆向思維 反過來從終點往起點找 + DFS
// 也可用海平面上升解
// O(mn)
class Solution {
public:
  int m, n;
  vector<int> dirs{0, 1, 0, -1, 0};
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    m = heights.size(), n = heights[0].size();

    vector<vector<int>> P(m, vector<int>(n, 0));
    vector<vector<int>> A(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
      dfs(heights, P, i, 0, 0);
      dfs(heights, A, i, n - 1, 0);
    }

    for (int j = 0; j < n; ++j) {
      dfs(heights, P, 0, j, 0);
      dfs(heights, A, m - 1, j, 0);
    }

    vector<vector<int>> res;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (P[i][j] && A[i][j])
          res.push_back({i, j});

    return res;
  }

  void dfs(vector<vector<int>> &heights, vector<vector<int>> &vis, int i, int j,
           int fromH) {
    if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j] ||
        heights[i][j] < fromH)
      return;

    vis[i][j] = 1;
    int h = heights[i][j];
    for (int k = 0; k < 4; ++k)
      dfs(heights, vis, i + dirs[k], j + dirs[k + 1], h);
  }
};