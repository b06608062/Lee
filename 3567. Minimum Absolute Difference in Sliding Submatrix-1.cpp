class Solution {
public:
  vector<vector<int>> minAbsDiff(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    if (k == 1)
      return vector<vector<int>>(m - k + 1, vector<int>(n - k + 1, 0));
    vector<vector<int>> res(m - k + 1, vector<int>(n - k + 1, INT_MAX / 2));
    for (int i = 0; i < m - k + 1; ++i) {
      for (int j = 0; j < n - k + 1; ++j) {
        set<int> sset;
        for (int di = 0; di < k; ++di)
          for (int dj = 0; dj < k; ++dj)
            sset.insert(grid[i + di][j + dj]);
        vector<int> arr(sset.begin(), sset.end());
        int sz = arr.size();
        if (sz == 1) {
          res[i][j] = 0;
          continue;
        }
        int &mn = res[i][j];
        for (int idx = 0; idx < sz - 1; ++idx)
          mn = min(mn, abs(arr[idx] - arr[idx + 1]));
      }
    }
    return res;
  }
};