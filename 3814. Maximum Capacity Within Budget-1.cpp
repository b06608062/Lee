// mark
// ???
// 10^5 * 10^5 too large
// 排序後枚舉右 + 二分搜尋找左 + 前綴最大值
// O(n log n)

class Solution {
public:
  int maxCapacity(vector<int> &costs, vector<int> &capacity, int budget) {
    int n = costs.size();
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
      arr.push_back({costs[i], capacity[i]});
    }
    sort(arr.begin(), arr.end());
    vector<int> pref_mx(n);
    pref_mx[0] = arr[0].second;
    for (int i = 1; i < n; ++i)
      pref_mx[i] = max(pref_mx[i - 1], arr[i].second);

    int res = 0;
    for (int i = 0; i < n; ++i) {
      auto [cost, cap] = arr[i];
      // one
      if (cost < budget)
        res = max(res, cap);
      // two
      int remain = budget - cost - 1;
      if (remain <= 0)
        continue;
      int lo = 0, hi = i;
      while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (remain >= arr[mid].first)
          lo = mid + 1;
        else
          hi = mid;
      }
      int idx = lo - 1;
      if (idx >= 0)
        res = max(res, cap + pref_mx[idx]);
    }

    return res;
  }
};