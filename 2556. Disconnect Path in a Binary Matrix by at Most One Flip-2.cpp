// mark
// 2369
// 先計算每個點是否在某條從左上到右下的路徑上
// 把 gird 順時鐘旋轉 45 度，檢查去除首尾後每一層 i + j 是否只有一個點在路徑上
class Solution {
public:
  bool isPossibleToCutPath(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<vector<int>> vis1 = grid, vis2 = grid;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if ((i != 0 || j != 0) && vis1[i][j])
          vis1[i][j] =
              (i > 0 ? vis1[i - 1][j] : 0) || (j > 0 ? vis1[i][j - 1] : 0);

    for (int i = m - 1; i >= 0; --i)
      for (int j = n - 1; j >= 0; --j)
        if ((i != m - 1 || j != n - 1) && vis2[i][j])
          vis2[i][j] = (i + 1 < m ? vis2[i + 1][j] : 0) ||
                       (j + 1 < n ? vis2[i][j + 1] : 0);

    vector<int> cnt(m + n - 1, 0);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (vis1[i][j] && vis2[i][j])
          cnt[i + j]++;

    for (int l = 1; l < m + n - 1 - 1; ++l)
      if (cnt[l] <= 1)
        return true;

    return false;
  }
};