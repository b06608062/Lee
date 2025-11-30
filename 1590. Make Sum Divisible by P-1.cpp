class Solution {
public:
  int minSubarray(vector<int> &nums, int p) {
    long long sum = accumulate(nums.begin(), nums.end(), 0ll);
    if (sum % p == 0)
      return 0;

    int n = nums.size();
    int k = sum % p;

    unordered_map<int, int> umap; // mod, idx

    umap[0] = -1;
    int cur = 0, res = INT_MAX;
    for (int i = 0; i < n; ++i) {
      cur += nums[i];
      cur %= p;
      int tgt = (cur - k + p) % p;
      if (umap.count(tgt)) {
        if (i - umap[tgt] < res)
          res = i - umap[tgt];
      }
      umap[cur] = i;
    }

    return (res == INT_MAX || res == n) ? -1 : res;
  }
};