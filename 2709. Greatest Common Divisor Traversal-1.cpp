struct DSU {
  vector<int> p, sz;
  DSU(int n) : p(n), sz(n, 1) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b)
      return false;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];

    return true;
  }
};

class Solution {
public:
  bool canTraverseAllPairs(vector<int> &nums) {
    int n = nums.size();

    int maxN = *max_element(nums.begin(), nums.end());
    vector<int> prime = findPrime(maxN);
    int m = prime.size();
    DSU dsu(n + m);

    unordered_map<int, int> p2idx;
    for (int i = 0; i < m; ++i)
      p2idx[prime[i]] = n + i;

    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      for (auto p : prime) {
        if (p > x)
          break;
        if (p * p > x) {
          dsu.unite(i, p2idx[x]);
          break;
        }
        if (x % p == 0) {
          dsu.unite(i, p2idx[p]);
          while (x % p == 0)
            x /= p;
        }
      }
    }

    int root = dsu.find(0);
    for (int i = 1; i < n; ++i)
      if (dsu.find(i) != root)
        return false;
    return true;
  }
  vector<int> findPrime(int n) {
    vector<int> sieve(n + 1, 0);
    int sqrtN = sqrt(n);
    for (int i = 2; i <= sqrtN; ++i) {
      if (sieve[i])
        continue;
      int j = i * i;
      while (j <= n) {
        sieve[j] = 1;
        j += i;
      }
    }

    vector<int> primes;
    for (int i = 2; i <= n; ++i)
      if (!sieve[i])
        primes.push_back(i);
    return primes;
  }
};