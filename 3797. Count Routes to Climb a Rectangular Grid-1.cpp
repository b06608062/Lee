// mark
// ???
// Grid DP + Prefix Sum Optimized DP
class Solution {
public:
  int numberOfRoutes(vector<string> &grid, int d) {
    const int MOD = 1e9 + 7;
    int n = grid.size(), m = grid[0].size();
    int dd = (int)sqrt(d * d - 1);

    vector<long long> dpS(m, 0), dpU(m, 0);

    for (int j = 0; j < m; ++j)
      if (grid[n - 1][j] == '.')
        dpU[j] = 1;

    vector<long long> prefU(m + 1, 0), prefT(m + 1, 0);
    for (int j = 1; j <= m; ++j)
      prefU[j] = (prefU[j - 1] + dpU[j - 1]) % MOD;
    for (int j = 0; j < m; ++j) {
      if (grid[n - 1][j] == '.') {
        int l = max(0, j - d);
        int r = min(m - 1, j + d);
        long long sum = (prefU[r + 1] - prefU[l] + MOD) % MOD;
        dpS[j] = (sum - dpU[j] + MOD) % MOD;
      }
    }

    for (int r = n - 2; r >= 0; --r) {
      vector<long long> nxtS(m, 0), nxtU(m, 0);
      fill(prefT.begin(), prefT.end(), 0);
      for (int j = 1; j <= m; ++j)
        prefT[j] = (prefT[j - 1] + dpU[j - 1] + dpS[j - 1]) % MOD;
      for (int j = 0; j < m; ++j) {
        if (grid[r][j] == '.') {
          int l = max(0, j - dd);
          int r = min(m - 1, j + dd);
          nxtU[j] = (prefT[r + 1] - prefT[l] + MOD) % MOD;
        }
      }
      fill(prefU.begin(), prefU.end(), 0);
      for (int j = 1; j <= m; ++j)
        prefU[j] = (prefU[j - 1] + nxtU[j - 1]) % MOD;
      for (int j = 0; j < m; ++j) {
        if (grid[r][j] == '.') {
          int l = max(0, j - d);
          int r = min(m - 1, j + d);
          long long sum = (prefU[r + 1] - prefU[l] + MOD) % MOD;
          nxtS[j] = (sum - nxtU[j] + MOD) % MOD;
        }
      }
      dpS.swap(nxtS);
      dpU.swap(nxtU);
    }

    long long res = 0;
    for (int j = 0; j < m; ++j)
      res += dpS[j] + dpU[j];
    return res % MOD;
  }
};