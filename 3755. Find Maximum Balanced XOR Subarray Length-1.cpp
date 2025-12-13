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
  int maxBalancedSubarray(vector<int> &nums) {
    int n = nums.size();
    unordered_map<pair<int, int>, int, PairHash<int, int>> umap;

    umap[{0, 0}] = -1;
    int cur = 0, diff = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      cur ^= x;
      diff += (x % 2) ? 1 : -1;
      pair<int, int> key = {cur, diff};
      if (umap.count(key))
        res = max(res, i - umap[key]);
      else
        umap[key] = i;
    }

    return res;
  }
};