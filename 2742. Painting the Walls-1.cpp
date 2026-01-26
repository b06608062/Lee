// 2425
// mark
// diff dp
// 預扣 + 由現在推未來 + 狀態剪枝
// TO ADD
class Solution {
  const int INF = INT_MAX / 2;
  int dp[505][505 * 2];
  int offset = 505;

public:
  int paintWalls(vector<int> &cost, vector<int> &time) {
    int n = cost.size();
    cost.insert(cost.begin(), 0);
    time.insert(time.begin(), 0);
    for (int i = 0; i <= n; ++i) {
      for (int j = -n; j <= n; ++j) {
        dp[i][j + offset] = INF;
      }
    }

    dp[0][offset] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = -n; j <= n; ++j) {
        dp[i + 1][j - 1 + offset] =
            min(dp[i + 1][j - 1 + offset], dp[i][j + offset]);
        int nj = min(j + time[i + 1], n);
        dp[i + 1][nj + offset] =
            min(dp[i + 1][nj + offset], dp[i][j + offset] + cost[i + 1]);
      }
    }

    int res = INF;
    for (int j = 0; j <= n; ++j) {
      res = min(res, dp[n][j + offset]);
    }

    return res;
  }
};