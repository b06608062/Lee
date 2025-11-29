class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    vector<int> dp(n, 0);

    dp[0] = nums[0];
    dp[1] = nums[1];
    for (int i = 2; i < n; ++i)
      for (int j = 0; j < i - 1; ++j)
        dp[i] = max(dp[i], dp[j] + nums[i]);

    return max(dp[n - 1], dp[n - 2]);
  }
};

class Solution {
public:
  int rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 1)
      return nums[0];

    vector<int> dp(n, 0); // 一定偷第 i 間的最大金額

    dp[0] = nums[0];
    dp[1] = nums[1];
    for (int i = 2; i < n; ++i)
      for (int j = max(0, i - 3); j < i - 1; ++j)
        dp[i] = max(dp[i], dp[j] + nums[i]);

    return max(dp[n - 1], dp[n - 2]);
  }
};