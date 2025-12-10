// mark
// 1982
// 倍數容斥原理 + DP
// 設 F[g] = 從每個 row 各選一個數，且每個被選中的數都能被 g 整除的方法數
// 設 G[g] = 從每個 row 選一個數且這些數的 GCD 恰好是 g 的方法數
// G[g] = F[g] - Σ G[kg]，其中 k ≥ 2 且 kg ≤ mx
// O (m * n * U + U log U)
class Solution {
public:
  int countCoprime(vector<vector<int>> &mat) {
    const int MOD = 1e9 + 7;
    int mx = 0;
    for (auto &row : mat)
      mx = max(mx, ranges::max(row));

    vector<int> G(mx + 1, 0);
    for (int g = mx; g > 0; --g) {
      long long res = 1;
      for (auto &row : mat) {
        int cnt = 0;
        for (int x : row)
          if (x % g == 0)
            cnt++;
        if (cnt == 0) {
          res = 0;
          break;
        }
        res = res * cnt % MOD;
      }
      for (int j = 2; g * j <= mx; ++j)
        res -= G[g * j];
      G[g] = (res % MOD + MOD) % MOD;
    }

    return G[1];
  }
};