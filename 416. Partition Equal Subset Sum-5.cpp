class Solution {
public:
  vector<vector<int>> memo;
  int n, target;
  bool canPartition(vector<int> &nums) {
    n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;
    target = sum / 2;
    memo.assign(n, vector<int>(target + 1, -1));
    return dfs(nums, n - 1, target);
  }

  int dfs(vector<int> &nums, int i, int cur) {
    if (cur < 0)
      return 0;
    if (i < 0)
      return cur == 0 ? 1 : 0;
    int &res = memo[i][cur];
    if (res != -1)
      return res;
    return res = dfs(nums, i - 1, cur) | dfs(nums, i - 1, cur - nums[i]);
  }
};