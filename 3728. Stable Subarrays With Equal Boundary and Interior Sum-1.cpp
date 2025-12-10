// mark
// 1909
// 多維前綴配對 + 延遲更新哈希表
template <class T1, class T2> struct PairHash {
  size_t operator()(const pair<T1, T2> &p) const noexcept {
    size_t h1 = hash<T1>{}(p.first);
    size_t h2 = hash<T2>{}(p.second);
    size_t h = h1;
    h ^= h2 + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
    return h;
  }
};

class Solution {
public:
  long long countStableSubarrays(vector<int> &capacity) {
    int n = capacity.size();

    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
      pref[i] = pref[i - 1] + capacity[i - 1];

    unordered_map<pair<long long, long long>, int,
                  PairHash<long long, long long>>
        umap;

    long long res = 0;
    for (int i = 0; i < n; ++i) {
      if (i - 2 >= 0) {
        int l = i - 2;
        umap[{capacity[l], pref[l + 1]}]++;
      }
      int x = capacity[i];
      res += umap[{x, pref[i] - x}];
    }

    return res;
  }
};