class Solution {
public:
  int countNegatives(vector<vector<int>> &grid) {
    int n = grid[0].size();

    int res = 0;
    for (auto &row : grid) {
      int l = 0, r = n;
      while (l < r) {
        int m = l + (r - l) / 2;
        if (row[m] >= 0)
          l = m + 1;
        else
          r = m;
      }
      res += n - r;
    }

    return res;
  }
};