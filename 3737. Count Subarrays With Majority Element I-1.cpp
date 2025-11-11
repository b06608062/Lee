class Solution {
public:
  int countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();

    unordered_map<int, int> umap;
    umap[0] = 1;

    int cur = 0, res = 0;
    for (auto x : nums) {
      cur += x == target ? 1 : -1;
      for (auto [k, v] : umap)
        if (k < cur)
          res += v;
      umap[cur]++;
    }

    return res;
  }
};