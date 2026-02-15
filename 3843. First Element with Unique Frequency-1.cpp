class Solution {
public:
  int firstUniqueFreq(vector<int> &nums) {
    unordered_map<int, int> umap1;
    for (auto x : nums)
      umap1[x]++;
    unordered_map<int, int> umap2;
    for (auto &[_, v] : umap1)
      umap2[v]++;

    for (auto x : nums)
      if (umap2[umap1[x]] == 1)
        return x;
    return -1;
  }
};