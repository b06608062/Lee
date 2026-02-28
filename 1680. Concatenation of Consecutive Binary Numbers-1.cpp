class Solution {
public:
  int concatenatedBinary(int n) {
    const int MOD = 1e9 + 7;
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
      int w = bit_width((uint32_t)i);
      for (int j = w - 1; j >= 0; --j)
        res = ((res << 1) | ((i >> j) & 1)) % MOD;
    }
    return res % MOD;
  }
};