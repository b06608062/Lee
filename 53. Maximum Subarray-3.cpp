// TLE
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int n = nums.size();

    int res = INT_MIN / 2;
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = i; j < n; ++j) {
        sum += nums[j];
        res = max(res, sum);
      }
    }

    return res;
  }
};