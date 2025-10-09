class Solution {
public:
  int cur, res;
  int subsetXORSum(vector<int> &nums) {
    cur = res = 0;
    helper(nums, 0);

    return res;
  }
  void helper(vector<int> &nums, int start) {
    res += cur;

    for (int i = start; i < nums.size(); ++i) {
      cur ^= nums[i];
      helper(nums, i + 1);
      cur ^= nums[i];
    }
  }
};