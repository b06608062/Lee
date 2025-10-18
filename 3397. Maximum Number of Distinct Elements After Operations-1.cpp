class Solution {
public:
  int maxDistinctElements(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    int cur = nums[0] - k, res = 0;
    for (auto x : nums) {
      if (cur >= x - k && cur <= x + k)
        cur++, res++;
      else if (x - k > cur) {
        cur = x - k + 1, res++;
      } else // x + k < cur
        continue;
    }

    return res;
  }
};