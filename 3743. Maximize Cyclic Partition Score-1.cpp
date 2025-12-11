// mark
// 3125
// 環狀問題轉換成兩個線性問題之聯集 最大元素在分割區間的最左或或最右
// 股票交易模型 + 可做空或做多 + 限制交易次數
// 可做空或做多 -> 找區間最大差值
// 限制交易次數 -> 限制分割區間數量
class Solution {
public:
  long long maximumScore(vector<int> &nums, int k) {
    auto it = max_element(nums.begin(), nums.end());

    vector<int> left, right;
    left.insert(left.end(), it, nums.end());
    left.insert(left.end(), nums.begin(), it);
    right.insert(right.end(), it + 1, nums.end());
    right.insert(right.end(), nums.begin(), it + 1);

    return max(helper(left, k), helper(right, k));
  }

  const long long inf = LONG_MIN / 2;
  long long helper(vector<int> &nums, int k) {
    int n = nums.size();

    vector<vector<array<long long, 3>>> dp =
        vector(n, vector<array<long long, 3>>(k + 1, {inf, inf, inf}));
    for (int j = 0; j <= k; ++j) {
      dp[0][j][0] = 0;
      dp[0][j][1] = j > 0 ? -nums[0] : inf;
      dp[0][j][2] = j > 0 ? nums[0] : inf;
    }

    for (int i = 1; i < n; ++i) {
      int x = nums[i];
      for (int j = 0; j <= k; ++j) {
        // rest
        dp[i][j][0] =
            max(dp[i - 1][j][0], max(dp[i - 1][j][1] + x, dp[i - 1][j][2] - x));

        // buy
        dp[i][j][1] = dp[i - 1][j][1];
        if (j > 0)
          dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j - 1][0] - x);

        // sell
        dp[i][j][2] = dp[i - 1][j][2];
        if (j > 0)
          dp[i][j][2] = max(dp[i][j][2], dp[i - 1][j - 1][0] + x);
      }
    }

    return dp[n - 1][k][0];
  }
};