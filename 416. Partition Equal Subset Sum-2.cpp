class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;

    int n = nums.size();
    int target = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= n; ++i)
      dp[i][0] = 1;

    for (int i = 1; i <= n; ++i) {
      int x = nums[i - 1];
      for (int j = 1; j <= target; ++j) {
        dp[i][j] = dp[i - 1][j];
        if (j - x >= 0)
          dp[i][j] |= dp[i - 1][j - x];
      }
    }

    return dp[n][target];
  }
};