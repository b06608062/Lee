class Solution {
public:
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> umap;

    for (int i = 0; i < nums.size(); ++i) {
      int x = nums[i];
      if (umap.count(target - x))
        return {umap[target - x], i};
      umap[x] = i;
    }

    return {-1, -1};
  }
};