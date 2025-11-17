// TLE
class Solution {
public:
  vector<long long> countStableSubarrays(vector<int> &nums,
                                         vector<vector<int>> &queries) {
    int n = nums.size();
    vector<long long> res;
    vector<long long> dp(n, 0);

    dp[0] = 1;
    for (int i = 1; i < n; ++i) {
      dp[i] = nums[i] >= nums[i - 1] ? dp[i - 1] + 1 : 1;
    }

    for (auto &q : queries) {
      int l = q[0], r = q[1];
      long long sum = 0;
      for (int i = l; i <= r; ++i)
        sum += min(0ll + i - l + 1, dp[i]);
      res.push_back(sum);
    }

    return res;
  }
};