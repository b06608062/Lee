// mark
// 2209
// 合法右端點非遞增子序列前綴和 + 下一非遞增子序列起點
// 一個長度為 m 的非遞增子序列，有 m * (m + 1) / 2 個穩定子陣列
class Solution {
public:
  vector<long long> countStableSubarrays(vector<int> &nums,
                                         vector<vector<int>> &queries) {
    int n = nums.size();

    vector<long long> pref(n + 1, 0);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (i > 0 && nums[i] < nums[i - 1])
        cnt = 0;
      cnt++;
      pref[i + 1] = pref[i] + cnt;
    }

    vector<int> next(n);
    next[n - 1] = n;
    for (int i = n - 2; i >= 0; --i)
      next[i] = nums[i] <= nums[i + 1] ? next[i + 1] : i + 1;

    vector<long long> res;
    for (auto &q : queries) {
      int l = q[0], r = q[1];
      int l2 = next[l];
      if (l2 > r) {
        // l, r 在同一非遞增子序列區間
        long long m = r - l + 1;
        res.push_back(m * (m + 1) / 2);
      } else {
        long long m = l2 - l;
        res.push_back(m * (m + 1) / 2 + pref[r + 1] - pref[l2]);
      }
    }

    return res;
  }
};