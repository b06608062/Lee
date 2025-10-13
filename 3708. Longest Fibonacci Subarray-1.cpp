class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();

    vector<int> dp(n, 0);

    for (int i = 2; i < n; ++i)
      if (nums[i - 1] + nums[i - 2] == nums[i])
        dp[i] = max(3, dp[i - 1] + 1);

    int res = *max_element(dp.begin(), dp.end());

    return max(2, res);
  }
};