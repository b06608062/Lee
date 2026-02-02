class Solution {
public:
  int longestAlternating(vector<int> &nums) {
    int n = nums.size();
    vector<int> pref_up(n, 1), pref_down(n, 1), suff_up(n, 1), suff_down(n, 1);
    int res = 1;
    for (int i = 1; i < n; ++i) {
      int x1 = nums[i - 1], x2 = nums[i];
      if (x2 > x1) {
        pref_up[i] = pref_down[i - 1] + 1;
      } else if (x1 > x2) {
        pref_down[i] = pref_up[i - 1] + 1;
      }
      res = max({res, pref_up[i], pref_down[i]});
    }

    for (int i = n - 2; i >= 0; --i) {
      int x1 = nums[i], x2 = nums[i + 1];
      if (x1 > x2) {
        suff_up[i] = suff_down[i + 1] + 1;
      } else if (x1 < x2) {
        suff_down[i] = suff_up[i + 1] + 1;
      }
      // res = max({res, suff_down[i], suff_up[i]});
    }

    for (int i = 1; i < n - 1; ++i) {
      int x1 = nums[i - 1], x2 = nums[i + 1];
      if (x1 > x2) {
        res = max(res, pref_up[i - 1] + suff_down[i + 1]);
      } else if (x1 < x2) {
        res = max(res, pref_down[i - 1] + suff_up[i + 1]);
      }
    }

    return res;
  }
};