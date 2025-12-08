// mark
// 1500
// 質數篩選 + 質因數分解模擬
class Solution {
public:
  int smallestValue(int n) {
    vector<int> primes = Eratosthenes(n);

    while (true) {
      int cur = n, sum = 0;
      for (auto p : primes) {
        if (p * p > cur)
          break;
        while (cur % p == 0) {
          cur /= p;
          sum += p;
        }
      }
      if (cur > 1)
        sum += cur;

      if (sum == n)
        break;
      n = sum;
    }

    return n;
  }

  vector<int> Eratosthenes(int n) {
    vector<int> sieve(n + 1, 0);
    vector<int> primes;

    for (int i = 2; i <= sqrt(n); ++i) {
      if (sieve[i] == 1)
        continue;
      int j = i * i;
      while (j <= n) {
        sieve[j] = 1;
        j += i;
      }
    }

    for (int i = 2; i <= n; ++i)
      if (sieve[i] == 0)
        primes.push_back(i);

    return primes;
  }
};