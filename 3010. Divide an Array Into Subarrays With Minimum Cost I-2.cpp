// mark
// 1292
// 劃分型 DP
// dp[i][k] = min(dp[i][k], dp[j][k - 1] + nums[i]);

class Solution {
public:
  int minimumCost(vector<int> &nums) {
    const int INF = INT_MAX / 2;
    int n = nums.size();
    vector dp(n, vector<int>(4, INF));

    dp[0][1] = nums[0];
    for (int i = 1; i < n; ++i) {
      for (int k = 2; k <= 3; ++k) {
        for (int j = i - 1; j >= 0; --j) {
          dp[i][k] = min(dp[i][k], dp[j][k - 1] + nums[i]);
        }
      }
    }

    int res = INF;
    for (int i = 2; i < n; ++i) {
      res = min(res, dp[i][3]);
    }

    return res;
  }
};