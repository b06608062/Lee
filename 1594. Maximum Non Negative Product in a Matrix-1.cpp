// mark
// 1807
// 自己初始化邊界，否則會構造非法起點

class Solution {
public:
  int maxProductPath(vector<vector<int>> &grid) {
    const int MOD = 1e9 + 7;
    int m = grid.size(), n = grid[0].size();

    vector<vector<long long>> mx(m, vector<long long>(n));
    vector<vector<long long>> mn(m, vector<long long>(n));

    mx[0][0] = mn[0][0] = grid[0][0];

    for (int i = 1; i < m; ++i)
      mx[i][0] = mn[i][0] = mx[i - 1][0] * grid[i][0];

    for (int j = 1; j < n; ++j)
      mx[0][j] = mn[0][j] = mx[0][j - 1] * grid[0][j];

    for (int i = 1; i < m; ++i) {
      for (int j = 1; j < n; ++j) {
        long long x = grid[i][j];
        long long a = mx[i - 1][j] * x;
        long long b = mx[i][j - 1] * x;
        long long c = mn[i - 1][j] * x;
        long long d = mn[i][j - 1] * x;
        mx[i][j] = max({a, b, c, d});
        mn[i][j] = min({a, b, c, d});
      }
    }

    long long res = mx[m - 1][n - 1];
    return res < 0 ? -1 : res % MOD;
  }
};