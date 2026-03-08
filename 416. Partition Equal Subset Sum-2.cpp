class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2)
      return false;
    int target = sum / 2;
    vector<vector<bool>> f(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; ++i)
      f[i][0] = true;

    for (int i = 1; i <= n; ++i) {
      int x = nums[i - 1];
      for (int j = 1; j <= target; ++j) {
        f[i][j] = f[i - 1][j];
        if (j - x >= 0)
          f[i][j] = f[i][j] || f[i - 1][j - x];
      }
    }
    return f[n][target];
  }
};