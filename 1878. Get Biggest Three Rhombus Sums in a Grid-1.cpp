// mark
// 1898
// 暴力枚舉 + 矩陣斜對角遍歷操作

class Solution {
public:
  vector<int> getBiggestThree(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    set<int> sset;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        sset.insert(grid[i][j]);
        for (int k = 1;; ++k) {
          if (i + 2 * k >= m || j - k < 0 || j + k >= n)
            break;
          int sum = 0;
          for (int t = 0; t < k; ++t) {
            // top -> right
            sum += grid[i + t][j + t];
            // right -> bottom
            sum += grid[i + k + t][j + k - t];
            // bottom -> left
            sum += grid[i + 2 * k - t][j - t];
            // left -> top
            sum += grid[i + k - t][j - k + t];
          }
          sset.insert(sum);
        }
      }
    }

    vector<int> res;
    for (auto it = sset.rbegin(); it != sset.rend() && res.size() < 3; ++it)
      res.push_back(*it);
    return res;
  }
};