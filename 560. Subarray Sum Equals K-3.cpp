class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    unordered_map<int, int> umap;

    umap[0] = 1;
    int sum = 0, res = 0;
    for (int x : nums) {
      sum += x;
      if (umap.count(sum - k))
        res += umap[sum - k];
      umap[sum]++;
    }

    return res;
  }
};
