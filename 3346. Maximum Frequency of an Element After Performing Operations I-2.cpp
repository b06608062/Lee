class Solution {
public:
  int maxFrequency(vector<int> &nums, int k, int numOperations) {
    int maxN = *max_element(nums.begin(), nums.end()) + k;
    int minN = *min_element(nums.begin(), nums.end()) - k;

    unordered_map<int, int> umap;

    int total = maxN - minN + 1, offset = minN;
    vector<int> diff(total, 0);

    for (auto x : nums) {
      umap[x]++;
      diff[x - k - offset]++;
      if (x + k + 1 - offset < total)
        diff[x + k + 1 - offset]--;
    }

    int cur = 0, res = 0;
    for (int i = 0; i < total; ++i) {
      cur += diff[i];
      int x = i + offset;
      res = max(res, min(umap[x] + numOperations, cur));
    }

    return res;
  }
};