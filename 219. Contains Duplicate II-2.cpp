class Solution {
public:
  bool containsNearbyDuplicate(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> umap;

    for (int i = 0; i < n; ++i) {
      int x = nums[i];
      if (umap.count(x))
        if (i - umap[x] <= k)
          return true;
      umap[x] = i;
    }

    return false;
  }
};