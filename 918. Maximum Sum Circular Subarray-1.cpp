class Solution {
public:
  int maxSubarraySumCircular(vector<int> &nums) {
    int sum = 0;
    int currMin = INT_MAX / 2, currMax = INT_MIN / 2;
    int maxRes = INT_MIN / 2, minRes = INT_MAX / 2;
    for (auto x : nums) {
      sum += x;

      currMin = min(currMin + x, x);
      currMax = max(currMax + x, x);

      minRes = min(minRes, currMin);
      maxRes = max(maxRes, currMax);
    }

    if (maxRes < 0)
      return maxRes;

    return max(maxRes, sum - minRes);
  }
};