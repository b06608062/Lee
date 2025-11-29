// reverse interval DP
class Solution {
public:
  int maxCoins(vector<int> &nums) {
    int n = nums.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; --i) {
      for (int j = i; j < n; ++j) {
        int best = 0;
        for (int k = i; k <= j; ++k) {
          int left = k > i ? dp[i][k - 1] : 0;
          int mid = (i - 1 >= 0 ? nums[i - 1] : 1) * nums[k] *
                    (j + 1 < n ? nums[j + 1] : 1);
          int right = k < j ? dp[k + 1][j] : 0;
          best = max(best, left + mid + right);
        }
        dp[i][j] = best;
      }
    }

    return dp[0][n - 1];
  }
};