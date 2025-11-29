class Solution {
public:
  long long maxSubarraySum(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, long long> umap;
    umap[0] = 0;

    long long cur = 0, res = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
      cur += nums[i];
      int mod = (i + 1) % k;
      if (umap.count(mod)) {
        res = max(res, cur - umap[mod]);
        umap[mod] = min(umap[mod], cur);
      } else
        umap[mod] = cur;
    }

    return res;
  }
};