class Solution {
public:
  vector<vector<int>> memo;
  int n;
  int maxCoins(vector<int> &nums) {
    n = nums.size();
    memo.assign(n, vector<int>(n, -1));
    return dfs(nums, 0, n - 1);
  }

  int dfs(vector<int> &nums, int i, int j) {
    if (i > j)
      return 0;
    int &res = memo[i][j];
    if (res != -1)
      return res;
    for (int k = i; k <= j; ++k) {
      int l_v = i - 1 >= 0 ? nums[i - 1] : 1;
      int r_v = j + 1 < n ? nums[j + 1] : 1;
      res = max(res, dfs(nums, i, k - 1) + l_v * nums[k] * r_v +
                         dfs(nums, k + 1, j));
    }
    return res;
  }
};