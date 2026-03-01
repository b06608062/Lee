class Solution {
public:
  vector<int> minDistinctFreqPair(vector<int> &nums) {
    unordered_map<int, int> umap;
    for (auto x : nums)
      umap[x]++;
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      for (int j = i + 1; j < n; ++j) {
        int y = nums[j];
        if (umap[x] != umap[y])
          return {x, y};
      }
    }
    return {-1, -1};
  }
};