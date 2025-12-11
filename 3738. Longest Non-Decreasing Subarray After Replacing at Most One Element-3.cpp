// mark
// 1811
// 狀態機 DP + 設計末尾元素不可改
// 重點是狀態定義
class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int n = nums.size();
    if (n <= 2)
      return n;

    // dp[i][0]: 以 i 結尾，不能改任何數的最長非減子陣列長度
    // dp[i][1]: 以 i 結尾，可以改一個數的最長非減子陣列長度，且 nums[i] 不能改
    vector<array<int, 2>> dp(n);
    dp[0] = {1, 1};

    int res = 2;
    for (int i = 1; i < n; ++i) {
      if (nums[i] >= nums[i - 1])
        dp[i][0] = dp[i - 1][0] + 1;
      else
        dp[i][0] = 1;
      // dp[i][0] + 1: 以 i + 1 結尾，正好改 nums[i + 1] 的最長非減子陣列長度
      res = max(res, dp[i - 1][0] + 1);
    }

    dp[1][1] = 2;
    for (int i = 2; i < n; ++i) {
      // base 改 i - 1 跟 i 拼在一起
      int best = 2;
      if (nums[i] >= nums[i - 1])
        // match 不改 i - 1 拼在 dp[i - 1][1] 後面
        best = max(best, dp[i - 1][1] + 1);
      if (nums[i] >= nums[i - 2])
        // 改 i - 1 拼在 dp[i - 2][0] 後面
        best = max(best, dp[i - 2][0] + 2);
      dp[i][1] = best;
      res = max(res, best);
    }

    return min(res, n);
  }
};