class Solution {
public:
  int maxSubArray(vector<int> &nums) {

    return helper(nums, 0, nums.size() - 1);
  }

  int helper(vector<int> &nums, int l, int r) {
    if (l == r)
      return nums[l];

    int m = l + (r - l) / 2;
    int leftMax = helper(nums, l, m);
    int rightMax = helper(nums, m + 1, r);

    int crossLeft = INT_MIN / 2;
    int cur = 0;
    for (int i = m; i >= l; --i) {
      cur += nums[i];
      crossLeft = max(crossLeft, cur);
    }

    int crossRight = INT_MIN / 2;
    cur = 0;
    for (int i = m + 1; i <= r; ++i) {
      cur += nums[i];
      crossRight = max(crossRight, cur);
    }

    return max(crossLeft + crossRight, max(leftMax, rightMax));
  }
};