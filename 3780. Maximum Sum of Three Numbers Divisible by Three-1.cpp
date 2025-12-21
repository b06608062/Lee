// mark
// ???
// 三維 DP + MOD + 選取數字
// MOD 要先確認前一個狀態有沒有值，才能進行轉移
class Solution {
public:
  int maximumSum(vector<int> &nums) {
    int n = nums.size();

    vector dp(n, vector(4, vector<int>(3, 0)));

    dp[0][1][nums[0] % 3] = nums[0];
    for (int i = 1; i < n; ++i) {
      int x = nums[i];
      dp[i] = dp[i - 1];
      dp[i][1][x % 3] = max(dp[i][1][x % 3], x);
      for (int j = 2; j <= 3; ++j) {
        for (int k = 0; k <= 2; ++k) {
          if (dp[i - 1][j - 1][k]) {
            int nxt = (x + k) % 3;
            dp[i][j][nxt] = max(dp[i][j][nxt], dp[i - 1][j - 1][k] + x);
          }
        }
      }
    }

    return dp[n - 1][3][0];
  }
};