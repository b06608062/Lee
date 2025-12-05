// mark
// 1687
// Sorting + Greedy 維護目前可用的最小值
class Solution {
public:
  int maxDistinctElements(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());

    int cur = INT_MIN, res = 0;
    for (auto x : nums)
      if (x + k >= cur) {
        res++;
        cur = max(cur + 1, x - k + 1);
      }

    return res;
  }
};