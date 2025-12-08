// mark
// 排序後用 DP 做「整除鏈」LIS 變形：
// dp[i] = 以 nums[i] 結尾的最大整除子集長度，prev[i] 記錄前一個索引以回溯答案
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> dp(n, 1), prev(n, -1);

    int maxEnd = 0, maxLen = 0;
    for (int i = 1; i < n; ++i) {
      int x = nums[i];
      for (int j = i - 1; j >= 0; --j) {
        if (x % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          prev[i] = j;
          if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxEnd = i;
          }
        }
      }
    }

    vector<int> res;
    int cur = maxEnd;
    while (cur != -1) {
      res.push_back(nums[cur]);
      cur = prev[cur];
    }
    reverse(res.begin(), res.end());

    return res;
  }
};