class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();

    vector<int> dp(n, 0);

    dp[0] = cost[0];
    dp[1] = cost[1];
    for (int i = 2; i < n; ++i)
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];

    return min(dp[n - 1], dp[n - 2]);
  }
};

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    cost.push_back(0);
    vector<int> f(n + 1);
    f[0] = cost[0], f[1] = cost[1];
    for (int i = 2; i <= n; ++i)
      f[i] = min(f[i - 1], f[i - 2]) + cost[i];
    return f[n];
  }
};

class Solution {
public:
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    cost.push_back(0);
    int prev1 = cost[1], prev2 = cost[0];
    for (int i = 2; i <= n; ++i) {
      int cur = min(prev1, prev2) + cost[i];
      prev2 = prev1;
      prev1 = cur;
    }

    return prev1;
  }
};

class Solution {
public:
  vector<int> memo;
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    cost.push_back(0);
    memo.assign(n + 1, -1);
    return dfs(cost, n);
  }
  int dfs(vector<int> &cost, int i) {
    if (i <= 1)
      return cost[i];
    int &res = memo[i];
    if (res != -1)
      return res;
    return res = min(dfs(cost, i - 1), dfs(cost, i - 2)) + cost[i];
  }
};