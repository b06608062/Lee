class Solution {
public:
  int maxDistinctElements(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    int cur = nums[0] - k, res = 0;
    for (auto x : nums)
      if (x + k >= cur) {
        res++;
        cur = max(cur + 1, x - k + 1);
      }

    return res;
  }
};