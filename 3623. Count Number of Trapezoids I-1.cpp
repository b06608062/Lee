class Solution {
public:
  int countTrapezoids(vector<vector<int>> &points) {
    const int MOD = 1e9 + 7;
    unordered_map<int, int> umap;
    for (auto &p : points)
      umap[p[1]]++;

    vector<long long> comb;
    for (auto [_, cnt] : umap)
      if (cnt > 1) {
        long long c = 1LL * cnt * (cnt - 1) / 2;
        c %= MOD;
        comb.push_back(c);
      }

    int n = comb.size();
    if (n < 2)
      return 0;

    vector<long long> suff(n + 1, 0);
    for (int i = n - 1; i >= 0; --i)
      suff[i] = (suff[i + 1] + comb[i]) % MOD;

    long long res = 0;
    for (int i = 0; i < n; ++i) {
      res += comb[i] * (suff[i] - comb[i]) % MOD;
      res %= MOD;
    }

    return res >= 0 ? res : res + MOD;
  }
};
