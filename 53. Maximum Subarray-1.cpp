class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int curMax = INT_MIN / 2, res = INT_MIN / 2;
    for (auto x : nums) {
      curMax = max(curMax + x, x);
      res = max(res, curMax);
    }

    return res;
  }
};