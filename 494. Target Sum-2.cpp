class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    unordered_map<int, int> umap, temp; // i, count
    umap[0] = 1;

    for (auto x : nums) {
      temp.clear();
      for (auto [i, count] : umap) {
        temp[i + x] += count;
        temp[i - x] += count;
      }
      swap(umap, temp);
    }

    return umap[target];
  }
};