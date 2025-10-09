class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();

    int maxVal, minVal, res;
    maxVal = minVal = res = nums[0];
    for (int i = 1; i < n; ++i) {
      int x = nums[i];
      if (x < 0)
        swap(maxVal, minVal);

      maxVal = max(x, maxVal * x);
      minVal = min(x, minVal * x);

      res = max(res, maxVal);
    }

    return res;
  }
};