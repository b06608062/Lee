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
      // up
      int pref = 0;
      for (int j = 1; j < m; ++j) {
        pref += dn[i - 1][j - 1];
        if (pref >= MOD)
          pref -= MOD;
        up[i][j] = pref;
      }

      // dn
      int suff = 0;
      for (int j = m - 2; j >= 0; --j) {
        suff += up[i - 1][j + 1];
        if (suff >= MOD)
          suff -= MOD;
        dn[i][j] = suff;
      }
    }

    int res = 0;
    for (int j = 0; j < m; ++j) {
      res += up[n][j];
      if (res >= MOD)
        res -= MOD;
      res += dn[n][j];
      if (res >= MOD)
        res -= MOD;
    }

    return res;
  }
};