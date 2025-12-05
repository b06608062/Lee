// mark
// 1865
// 枚舉 + Binary Search 找範圍
class Solution {
public:
  int maxFrequency(vector<int> &nums, int k, int numOperations) {
    sort(nums.begin(), nums.end());

    unordered_map<int, int> umap;
    for (auto x : nums)
      umap[x]++;

    int minN = nums[0], maxN = nums.back(), res = 0;
    for (int i = minN; i <= maxN; ++i) {
      int lo = lower_bound(nums.begin(), nums.end(), i - k) - nums.begin();
      int hi = upper_bound(nums.begin(), nums.end(), i + k) - nums.begin() - 1;
      res = max(res, min(umap[i] + numOperations, hi - lo + 1));
    }

    return res;
  }
};