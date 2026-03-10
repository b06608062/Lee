class Solution {
public:
  vector<vector<int>> memo;
  int findTargetSumWays(vector<int> &nums, int target) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < abs(target) || (sum + target) % 2 != 0)
      return 0;
    int P = (sum + target) / 2;
    memo.assign(n, vector<int>(P + 1, -1));
    return dfs(nums, n - 1, P);
  }

  int dfs(vector<int> &nums, int i, int a) {
    if (i < 0 || a < 0)
      return a == 0 ? 1 : 0;
    int &res = memo[i][a];
    if (res != -1)
      return res;
    return res = dfs(nums, i - 1, a) + dfs(nums, i - 1, a - nums[i]);
  }
};