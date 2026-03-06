class Solution {
public:
  vector<int> memo;
  int minCostClimbingStairs(vector<int> &cost) {
    int n = cost.size();
    memo.assign(n + 1, -1);
    return dfs(cost, n);
  }
  int dfs(vector<int> &cost, int i) {
    if (i <= 1)
      return 0;
    int &res = memo[i];
    if (res != -1)
      return res;
    return res = min(dfs(cost, i - 1) + cost[i - 1],
                     dfs(cost, i - 2) + cost[i - 2]);
  }
};