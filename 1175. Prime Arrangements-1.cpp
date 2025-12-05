// mark
// 1489
// 排組 + 質數篩選 + 階乘取模
// 階乘導數取模運算 + 費馬小定理
const int MOD = 1e9 + 7;
const int MX = 101;

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
  int numPrimeArrangements(int n) {
    vector<int> prime = findPrime(n);
    int m = prime.size();

    return fac[m] * fac[n - m] % MOD;
  }

  // O(n log log n)
  vector<int> findPrime(int n) {
    vector<bool> sieve(n + 1, false);
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; ++i) {
      if (sieve[i])
        continue;
      int j = i * i;
      while (j <= n) {
        sieve[j] = true;
        j += i;
      }
    }

    vector<int> prime;
    for (int i = 2; i <= n; ++i)
      if (!sieve[i])
        prime.push_back(i);

    return prime;
  }
};