// mark
// 2302
// 恰好 -> 至少型滑窗相減
// 至少 k 個不同的數字 && 至少 k 個數字出現 m 次
// 至少 k + 1 個不同的數字 && 至少 k 個數字出現 m 次

class Solution {
public:
  long long countSubarrays(vector<int> &nums, int k, int m) {
    return helper(nums, k, m, k) - helper(nums, k, m, k + 1);
  }

  long long helper(vector<int> &nums, int k, int m, int g) {
    unordered_map<int, int> umap;
    long long res = 0;
    int l = 0, cur = 0;
    for (auto x : nums) {
      if (++umap[x] == m)
        cur++;
      while (umap.size() >= g && cur >= k) {
        int y = nums[l++];
        if (umap[y]-- == m)
          cur--;
        if (umap[y] == 0)
          umap.erase(y);
      }
      res += l;
    }
    return res;
  }
};