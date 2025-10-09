// TLE
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();

    int res = INT_MIN / 2;
    for (int i = 0; i < n; ++i)
      for (int j = i; j < n; ++j) {
        int sum = accumulate(nums.begin() + i, nums.begin() + j + 1, 0);
        res = max(res, sum);
      }

    return res;
  }
};