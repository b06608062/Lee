class Solution {
public:
  int numIdenticalPairs(vector<int> &nums) {
    unordered_map<int, int> umap;

    int res = 0;
    for (auto x : nums) {
      res += umap[x];
      umap[x]++;
    }

    return res;
  }
};