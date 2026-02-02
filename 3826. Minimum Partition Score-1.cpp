// TLE

class Solution {
public:
  long long minPartitionScore(vector<int> &nums, int k) {
    int n = nums.size();
    const long long INF = LLONG_MAX / 2;
    vector<long long> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      pref[i] = pref[i - 1] + nums[i - 1];
    }

    vector dp(n + 1, vector<long long>(k + 1, INF));
    dp[0][0] = 0;

    for (int i = 1; i <= n; ++i) {
      for (int j = i; j >= 1; --j) {
        long long cur = pref[i] - pref[j - 1];
        cur = cur * (cur + 1) / 2;
        for (int p = 1; p <= k; ++p) {
          dp[i][p] = min(dp[i][p], cur + dp[j - 1][p - 1]);
        }
      }
    }

    return dp[n][k];
  }
};