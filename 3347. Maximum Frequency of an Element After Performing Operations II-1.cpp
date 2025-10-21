class Solution {
public:
  int maxFrequency(vector<int> &nums, int k, int numOperations) {
    unordered_map<int, int> umap;
    map<int, int> mmap;

    for (auto x : nums) {
      umap[x]++;
      mmap[x - k]++;
      mmap[x] += 0;
      mmap[x + k + 1]--;
    }

    int cur = 0, res = 0;
    for (auto [x, f] : mmap) {
      cur += f;
      res = max(res, min(umap[x] + numOperations, cur));
    }

    return res;
  }
};