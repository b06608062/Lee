class Solution {
public:
  long long numGoodSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> umap;
    umap[0] = 1;

    int lastStart = 0;
    long long cur = 0, res = 0;
    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      if (i > 0 && x != nums[i - 1]) {
        long long temp = cur;
        for (int j = i - 1; j >= lastStart; --j) {
          umap[temp % k]++;
          temp -= nums[j];
        }
        lastStart = i;
      }
      cur += x;
      res += umap[cur % k];
    }

    return res;
  }
};