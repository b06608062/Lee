class Solution {
public:
  long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size(), m = nums2.size();
    long long INF = 1e15;
    vector dp(n + 1, vector(m + 1, vector<long long>(k + 1, -INF)));

    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= m; ++j) {
        dp[i][j][0] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        long long x = nums1[i - 1], y = nums2[j - 1];
        for (int kk = 1; kk <= k; ++kk) {
          dp[i][j][kk] = max({dp[i - 1][j][kk], dp[i][j - 1][kk],
                              dp[i - 1][j - 1][kk - 1] + 1ll * x * y});
        }
      }
    }

    return dp[n][m][k];
  }
};