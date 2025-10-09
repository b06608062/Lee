// TLE
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int n = nums.size();

    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= i; ++j)
        if (accumulate(nums.begin() + j, nums.begin() + i + 1, 0) == k)
          res++;
    }

    return res;
  }
};