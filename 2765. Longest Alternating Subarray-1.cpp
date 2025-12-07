// mark
// 1581
// Alternating DP + 初始條件處理
class Solution {
public:
  int alternatingSubarray(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, 0)); // up, down
    int res = 0;
    for (int i = 0; i < n - 1; ++i)
      if (nums[i] + 1 == nums[i + 1])
        dp[i][1] = 1;
    for (int i = 1; i < n; ++i) {
      int x = nums[i];
      if (x == nums[i - 1] + 1) {
        dp[i][0] = dp[i - 1][1] + 1;
        res = max(res, dp[i][0]);
      } else if (x == nums[i - 1] - 1 && dp[i - 1][0] != 0) {
        dp[i][1] = dp[i - 1][0] + 1;
        res = max(res, dp[i][1]);
      }
    }

    return res == 0 ? -1 : res;
  }
};

class Solution {
public:
  int alternatingSubarray(vector<int> &nums) {
    int n = nums.size();

    int up = 0, down = 0, res = 0;
    for (int i = 1; i < n; ++i) {
      if (nums[i] == nums[i - 1] + 1) {
        up = (down > 0 ? down + 1 : 2);
        down = 0;
        res = max(res, up);
      } else if (nums[i] == nums[i - 1] - 1 && up > 0) {
        down = up + 1;
        up = 0;
        res = max(res, down);
      } else
        up = down = 0;
    }

    return res == 0 ? -1 : res;
  }
};