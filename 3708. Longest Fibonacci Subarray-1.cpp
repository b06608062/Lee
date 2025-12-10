class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 2);

    int res = 2;
    for (int i = 2; i < n; ++i)
      if (nums[i] == nums[i - 1] + nums[i - 2]) {
        dp[i] = dp[i - 1] + 1;
        res = max(res, dp[i]);
      }

    return res;
  }
};