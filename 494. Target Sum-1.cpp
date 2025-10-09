class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target))
      return 0;

    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(sum * 2 + 1, 0));

    int offset = sum;
    dp[0][offset] = 1;
    for (int i = 1; i <= n; ++i) {
      int x = nums[i - 1];
      for (int j = 0; j < sum * 2 + 1; ++j) {
        if (!dp[i - 1][j])
          continue;
        if (j - x >= 0)
          dp[i][j - x] += dp[i - 1][j];
        if (j + x < sum * 2 + 1)
          dp[i][j + x] += dp[i - 1][j];
      }
    }

    return dp[n][target + offset];
  }
};