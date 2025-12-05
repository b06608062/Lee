// mark
// 1580
// 組合數計算 + Prefix Sum
class Solution {
public:
  int countTrapezoids(vector<vector<int>> &points) {
    int MOD = 1000000007;
    unordered_map<int, long long> umap;
    for (auto &p : points)
      umap[p[1]]++;
    long long res = 0, total = 0;
    for (auto &[_, cnt] : umap) {
      long long comb = (cnt * (cnt - 1) / 2) % MOD;
      res = (res + total * comb) % MOD;
      total = (total + comb) % MOD;
    }
    return res;
  }
};