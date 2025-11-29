class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    vector<array<int, 2>> dp(n, {0, 0}); // dp[i][0]: 不偷第 i 間房子的最大金額
                                         // dp[i][1]: 偷第 i 間房子的最大金額
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    for (int i = 1; i < n; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 1][0] + nums[i];
    }

    return max(dp[n - 1][0], dp[n - 1][1]);
  }
};