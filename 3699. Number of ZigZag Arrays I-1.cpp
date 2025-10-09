// TLE
class Solution {
public:
  int zigZagArrays(int n, int l, int r) {
    constexpr int MOD = 1e9 + 7;
    int m = r - l + 1;

    vector<vector<int>> up(n + 1, vector<int>(m, 0)),
        dn(n + 1, vector<int>(m, 0));

    for (int j = 0; j < m; ++j)
      up[1][j] = dn[1][j] = 1;

    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < m; ++j) {
        // up
        for (int k = 0; k < j; ++k) {
          up[i][j] += dn[i - 1][k];
          up[i][j] %= MOD;
        }

        // dn
        for (int k = j + 1; k < m; ++k) {
          dn[i][j] += up[i - 1][k];
          dn[i][j] %= MOD;
        }
      }
    }

    int res = 0;
    for (int j = 0; j < m; ++j) {
      res += up[n][j];
      res %= MOD;
      res += dn[n][j];
      res %= MOD;
    }

    return res;
  }
};