// mark
// 1974
// 延遲判斷 + Greedy 找最早的合法點 + 有序集合
class Solution {
public:
  vector<int> avoidFlood(vector<int> &rains) {
    int n = rains.size();

    set<int> sset;                // r = 0, idx
    unordered_map<int, int> umap; // r > 0, lakei -> idx

    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) {
      int r = rains[i];
      if (r == 0) {
        sset.insert(i);
        res[i] = 1;
      } else {
        // r > 0
        if (umap.count(r)) {
          int rIdx = umap[r];
          auto it = sset.upper_bound(rIdx);
          if (it == sset.end())
            return {};
          res[*it] = r;
          sset.erase(it);
        }
        umap[r] = i;
      }
    }

    return res;
  }
};