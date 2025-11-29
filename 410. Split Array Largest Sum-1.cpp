class Solution {
public:
  vector<vector<int>> memo;
  int splitArray(vector<int> &nums, int k) {
    int n = nums.size();
    memo.assign(n, vector<int>(k + 1, -1));

    return dfs(nums, n - 1, k);
  }

  int dfs(vector<int> &nums, int i, int k) {
    if (k < 0)
      return INT_MAX;
    if (i < 0)
      return k == 0 ? 0 : INT_MAX;
    if (memo[i][k] != -1)
      return memo[i][k];
    int res = INT_MAX;
    int cur = 0;
    for (int j = i; j >= 0; --j) {
      cur += nums[j];
      res = min(res, max(cur, dfs(nums, j - 1, k - 1)));
    }

    return memo[i][k] = res;
  }
};