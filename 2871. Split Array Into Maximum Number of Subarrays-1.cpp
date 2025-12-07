class Solution {
public:
  int maxSubarrays(vector<int> &nums) {
    int n = nums.size();

    int minAnd = INT_MAX;
    for (auto x : nums)
      minAnd &= x;
    if (minAnd)
      return 1;

    int cur = INT_MAX, res = 0;
    for (int i = 0; i < n; ++i) {
      cur &= nums[i];
      if (cur == 0) {
        res++;
        cur = INT_MAX;
      }
    }

    return res;
  }
};