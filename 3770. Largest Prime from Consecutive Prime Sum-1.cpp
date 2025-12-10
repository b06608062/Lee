class Solution {
public:
  int largestPrime(int n) {
    vector<int> prime = findPrime(n);
    int m = prime.size();

    unordered_set<long long> uset;

    long long cur = 0;
    int res = 0;
    for (auto p : prime) {
      if (cur + p <= n) {
        cur += p;
        uset.insert(cur);
      }
      if (uset.count(p))
        res = p;
    }

    return res;
  }

  vector<int> findPrime(int n) {
    vector<bool> sieve(n + 1, false);
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; ++i) {
      if (sieve[i])
        continue;
      long long j = i * i;
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