// mark
// 2694
// 位運算狀態壓縮 DP + 組合數學 + 費馬小定理 預處理階乘及其反元素
const int MOD = 1e9 + 7;
const int MX = 31;

long long fac[MX];  // fac[i] = i!
long long invF[MX]; // invF[i] = i!^-1

long long pow(long long a, int e) {
  long long res = 1;
  while (e) {
    if (e & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    e >>= 1;
  }

  return res;
}

auto init = [] {
  fac[0] = 1;
  for (int i = 1; i < MX; ++i) {
    fac[i] = fac[i - 1] * i % MOD;
  }

  // 費馬小定理
  // a^(p-1) ≡ 1 (mod p) ⇒ a * a^(p-2) ≡ 1 (mod p)
  // 即是說 a^(p-2) ≡ a^(-1) (mod p)
  // a^(p-2) ≡ a^(-1) (mod p)
  invF[MX - 1] = pow(fac[MX - 1], MOD - 2);
  // 由於 invF[i] = invF[i+1] * (i+1)，所以可以倒著算
  for (int i = MX - 2; i >= 0; --i) {
    invF[i] = invF[i + 1] * (i + 1) % MOD;
  }

  return 0;
}();

class Solution {
public:
  long long dp[50][MX][MX][MX]; // i, left_m, s, left_k
  long long powNum[50][MX];
  int n, m;
  int magicalSum(int m, int k, vector<int> &nums) {
    n = nums.size();
    this->m = m;

    for (int i = 0; i < n; ++i) {
      long long x = nums[i];
      for (int j = 0; j <= m; ++j)
        if (j == 0)
          powNum[i][j] = 1;
        else
          powNum[i][j] = powNum[i][j - 1] * x % MOD;
    }

    memset(dp, -1, sizeof(dp));

    return fac[m] * dfs(0, m, 0, k) % MOD;
  }

  long long dfs(int i, int left_m, int s, int left_k) {
    int pop_c = popcount((uint32_t)s);
    if (pop_c + left_m < left_k)
      return 0;

    if (i == n || left_m == 0 || left_k == 0)
      return left_m == 0 && pop_c == left_k;

    long long &res = dp[i][left_m][s][left_k];
    if (res != -1)
      return res;

    res = 0;
    for (int j = 0; j <= left_m; ++j) {
      res += dfs(i + 1, left_m - j, (s + j) >> 1, left_k - ((s + j) & 1)) *
             powNum[i][j] % MOD * invF[j] % MOD;
      res %= MOD;
    }

    return res % MOD;
  }
};