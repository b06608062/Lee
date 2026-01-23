// mark
// 2608
// 模擬 + 雙有序集合 + 維護前繼後繼索引

class Solution {
public:
  int minimumPairRemoval(vector<int> &nums) {
    int n = nums.size();
    // pre, it, net_it, nxt_it2
    int dec = 0;
    set<pair<long long, int>> pairs; // sum, idx;
    for (int i = 0; i < n - 1; ++i) {
      int x = nums[i], y = nums[i + 1];
      if (x > y) {
        dec++;
      }
      pairs.insert({x + y, i});
    }

    set<int> idx;
    for (int i = 0; i < n; ++i) {
      idx.insert(i);
    }

    int res = 0;
    vector<long long> a(nums.begin(), nums.end());
    while (dec > 0) {
      res++;
      auto [s, i] = *pairs.begin();
      pairs.erase(pairs.begin());
      auto it = idx.lower_bound(i);
      auto nxt_it = next(it);
      int nxt = *nxt_it;
      dec -= a[i] > a[nxt];
      if (it != idx.begin()) {
        int pre = *prev(it);
        dec -= a[pre] > a[i];
        dec += a[pre] > s;
        pairs.erase({a[pre] + a[i], pre});
        pairs.insert({a[pre] + s, pre});
      }

      auto nxt2_it = next(nxt_it);
      if (nxt2_it != idx.end()) {
        int nxt2 = *nxt2_it;
        dec -= a[nxt] > a[nxt2];
        dec += s > a[nxt2];
        pairs.erase({a[nxt] + a[nxt2], nxt});
        pairs.insert({s + a[nxt2], i});
      }

      a[i] = s;
      idx.erase(nxt);
    }

    return res;
  }
};