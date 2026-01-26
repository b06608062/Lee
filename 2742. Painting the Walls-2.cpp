// 2425
// mark
// 0/1 knapsack
// 預扣 + 由現在推未來 + 狀態剪枝
// dp[i][j] 考慮前 i 個工人，累積可完成的額度為 j 時的最小花費
// TO ADD
class Solution {
  const int INF = INT_MAX / 2;
  int dp[505][505];

public:
  int paintWalls(vector<int> &cost, vector<int> &time) {
    int n = cost.size();
    cost.insert(cost.begin(), 0);
    time.insert(time.begin(), 0);
    for (int i = 0; i <= n; ++i) {
      for (int j = 0; j <= n; ++j) {
        dp[i][j] = INF;
      }
    }

    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= n; ++j) {
        // 選
        dp[i + 1][min(n, j + time[i + 1] + 1)] =
            min(dp[i + 1][min(n, j + time[i + 1] + 1)], dp[i][j] + cost[i + 1]);
        // 不選
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
      }
    }

    return dp[n][n];
  }
};