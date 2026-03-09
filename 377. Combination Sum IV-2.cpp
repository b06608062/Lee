class Solution {
public:
  vector<int> memo;
  int combinationSum4(vector<int> &nums, int target) {
    memo.resize(target + 1, -1);
    return dfs(nums, target);
  }

  int dfs(vector<int> &nums, int t) {
    if (t < 0)
      return 0;
    if (t == 0)
      return 1;
    int &res = memo[t];
    if (res != -1)
      return res;
    res = 0;
    for (auto x : nums)
      res += dfs(nums, t - x);
    return res;
  }
};