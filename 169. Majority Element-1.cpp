class Solution {
public:
  int majorityElement(vector<int> &nums) {
    int n = nums.size();

    unordered_map<int, int> umap;
    for (auto x : nums)
      umap[x]++;

    for (auto [k, v] : umap)
      if (v > n / 2)
        return k;

    return -1;
  }
};
