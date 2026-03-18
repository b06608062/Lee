class Solution {
public:
  int memo[10001];
  int n;
  int solve(vector<int> &nums, int pos) {
    if (pos >= n - 1)
      return 0;

    int &res = memo[pos];
    if (res != -1)
      return res;

    res = INT_MAX / 2;
    for (int i = 1; i <= nums[pos]; ++i) {
      res = min(res, 1 + solve(nums, pos + i));
    }

    return res;
  }

  int jump(vector<int> &nums) {
    n = nums.size();
    memset(memo, -1, sizeof(memo));
    return solve(nums, 0);
  }
};