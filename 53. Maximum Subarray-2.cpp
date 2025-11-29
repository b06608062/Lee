class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int minPref = 0, cur = 0, res = INT_MIN;
    for (auto x : nums) {
      cur += x;
      res = max(res, cur - minPref);
      minPref = min(minPref, cur);
    }

    return res;
  }
};