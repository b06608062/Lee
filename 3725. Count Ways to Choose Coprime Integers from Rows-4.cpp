// mark
// 1982
// 倍數容斥原理 + 預處理因子 + DP
// 設 F[g] = 從每個 row 各選一個數，且每個被選中的數都能被 g 整除的方法數
// 設 G[g] = 從每個 row 選一個數且這些數的 GCD 恰好是 g 的方法數
// G[g] = F[g] - Σ G[kg]，其中 k ≥ 2 且 kg ≤ mx
// O(m * n * d(U) + m * U + U log U)
constexpr int MX = 151;
vector<int> divisors[MX];

int init = [] {
  for (int i = 1; i < MX; ++i)
    for (int j = i; j < MX; j += i) // 枚舉 i 的倍數 j
      divisors[j].push_back(i);     // i 是 j 的因子
  return 0;
}();

class Solution {
public:
  int countCoprime(vector<vector<int>> &mat) {
    const int MOD = 1e9 + 7;
    int m = mat.size();

    // 預處理每個 row 的因子個數
    vector<vector<int>> D(m, vector<int>(MX, 0));
    int mx = 0;
    // O(m * n * d(U))
    for (int i = 0; i < m; ++i) // m
      for (auto x : mat[i]) {   // n
        mx = max(mx, x);
        for (auto d : divisors[x]) // d(U) <= 16
          D[i][d]++;
      }

    vector<int> G(mx + 1, 0);
    for (int g = mx; g > 0; --g) {
      long long res = 1;
      for (auto &rowD : D) {
        if (rowD[g] == 0) {
          res = 0;
          break;
        }
        res = res * rowD[g] % MOD;
      }
      for (int j = 2; g * j <= mx; ++j)
        res -= G[g * j];
      G[g] = (res % MOD + MOD) % MOD;
    }

    return G[1];
  }
};