// mark
// ???
// O(log n) pow + 等差數列求和 + 費馬小定理乘法反元素

class Solution {
public:
  const long long MOD = 1e9 + 7;
  long long pow(long long x, long long e) {
    long long res = 1;
    x %= MOD;
    while (e) {
      if (e & 1)
        res = res * x % MOD;
      x = x * x % MOD;
      e >>= 1;
    }
    return res;
  }

  // 費馬小定理
  // a^(p-1) ≡ 1 (mod p) ⇒ a * a^(p-2) ≡ 1 (mod p)
  // 即是說 a * a^(-1) ≡ 1 (mod p)
  // a^(p-2) = a^(-1) (mod p)
  long long inv(long long x) { return pow(x, MOD - 2); }
  int sumOfNumbers(int l, int r, int k) {
    long long n = r - l + 1;
    long long pow_n = pow(n, k - 1);
    long long sum_d = 0;
    for (int i = l; i <= r; ++i)
      sum_d += i;
    // 10^0 + 10^1 + ... + 10^k-1 = (10^k - 1) / (10 - 1)
    long long prod = (pow(10, k) - 1 + MOD) % MOD * inv(10 - 1) % MOD;
    long long res = sum_d * pow_n % MOD * prod % MOD;
    return res;
  }
};