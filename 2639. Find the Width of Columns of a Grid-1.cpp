class Solution {
public:
  vector<int> findColumnWidth(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();

    vector<int> res(n, 0);
    for (int j = 0; j < n; ++j)
      for (int i = 0; i < m; ++i)
        res[j] = max(res[j], (int)to_string(grid[i][j]).size());

    return res;
  }
};