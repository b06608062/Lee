class Solution {
public:
  int countPermutations(vector<int> &complexity) {
    const int MOD = 1e9 + 7;
    int n = complexity.size();

    int minVal = complexity[0];
    for (int i = 1; i < n; ++i)
      if (complexity[i] <= minVal)
        return 0;

    vector<long long> fac(n + 1, 1);
    for (int i = 1; i <= n; ++i)
      fac[i] = fac[i - 1] * i % MOD;

    return fac[n - 1];
  }
};