class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int n = nums.size();

    vector<int> maxEnd(n), minEnd(n);

    int res;
    maxEnd[0] = minEnd[0] = res = nums[0];
    for (int i = 1; i < n; ++i) {
      int x = nums[i];
      maxEnd[i] = max({x, x * maxEnd[i - 1], x * minEnd[i - 1]});
      minEnd[i] = min({x, x * maxEnd[i - 1], x * minEnd[i - 1]});
      res = max(res, maxEnd[i]);
    }

    return res;
  }
};