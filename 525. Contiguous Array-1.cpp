class Solution {
public:
  int findMaxLength(vector<int> &nums) {
    unordered_map<int, int> umap; // diff, idx;

    umap[0] = -1;
    int zero = 0, one = 0, res = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i])
        one++;
      else
        zero++;
      int diff = one - zero;
      if (!umap.count(diff))
        umap[diff] = i;
      else
        res = max(res, i - umap[diff]);
    }

    return res;
  }
};