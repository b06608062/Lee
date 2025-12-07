class Solution {
public:
  int minSizeSubarray(vector<int> &nums, int target) {
    long long sum = accumulate(nums.begin(), nums.end(), 0ll);
    int k = target / sum;
    target %= sum;

    int n = nums.size();
    if (target == 0)
      return n * k;

    nums.insert(nums.end(), nums.begin(), nums.end());
    unordered_map<long long, int> umap;

    umap[0] = -1;
    long long cur = 0;
    int res = INT_MAX;
    for (int i = 0; i < n * 2; ++i) {
      cur += nums[i];
      if (umap.count(cur - target))
        res = min(res, i - umap[cur - target]);
      umap[cur] = i;
    }

    return res == INT_MAX ? -1 : n * k + res;
  }
};