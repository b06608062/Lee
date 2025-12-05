// TODO
// 2694
const int MOD = 1'000'000'007;
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

  invF[MX - 1] = pow(fac[MX - 1], MOD - 2); // 費馬小定理
  // 由於 invF[i] = invF[i+1] * (i+1)，所以可以倒著算
  for (int i = MX - 2; i >= 0; --i) {
    invF[i] = invF[i + 1] * (i + 1) % MOD;
  }

  return 0;
}();

class Solution {
public:
  int magicalSum(int m, int k, vector<int> &nums) {
    int n = nums.size();

    vector powNum(n, vector<int>(m + 1, 1));
    for (int i = 0; i < n; ++i) {
      long long x = nums[i];
      for (int j = 1; j <= m; ++j)
        powNum[i][j] = powNum[i][j - 1] * x % MOD;
    }

    vector memo(n, vector(m + 1, vector(m / 2 + 1, vector<int>(k + 1, -1))));

    auto dfs = [&](this auto &&dfs, int i, int leftM, int x, int leftK) -> int {
      int popC = popcount((uint32_t)x);
      if (popC + leftM < leftK)
        return 0;

      if (i == n || leftM == 0 || leftK == 0)
        return leftM == 0 && popC == leftK;

      int &res = memo[i][leftM][x][leftK];
      if (res != -1)
        return res;

      res = 0;
      for (int j = 0; j <= leftM; ++j) {
        int bit = (x + j) & 1;
        res = (res + 1LL * dfs(i + 1, leftM - j, (x + j) >> 1, leftK - bit) *
                         powNum[i][j] % MOD * invF[j]) %
              MOD;
      }

      return res;
    };

    return 1LL * dfs(0, m, 0, k) * fac[m] % MOD;
  }
};