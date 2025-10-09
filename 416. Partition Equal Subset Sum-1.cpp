class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;

    int target = sum / 2;
    vector<int> dp(target + 1, 0);

    dp[0] = 1;
    for (auto x : nums)
      for (int i = target; i - x >= 0; --i)
        if (dp[i - x])
          dp[i] = 1;

    return dp[target];
  }
};