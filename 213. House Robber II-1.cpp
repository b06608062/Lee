class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    return max(helper(nums, 0, n - 2), helper(nums, 1, n - 1));
  }

  int helper(vector<int> &nums, int start, int end) {
    if (start == end)
      return nums[start];

    int n = end - start + 1;
    vector<int> dp(n, 0);

    dp[0] = nums[start];
    dp[1] = max(nums[start], nums[start + 1]);
    for (int i = 2; i < n; ++i)
      dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);

    return dp[n - 1];
  }
};