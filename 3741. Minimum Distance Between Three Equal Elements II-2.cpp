class Solution {
public:
  int minimumDistance(vector<int> &nums) {
    int n = nums.size();

    unordered_map<int, int> umap1, umap2;

    int res = INT_MAX / 2;
    for (int k = 0; k < n; ++k) {
      int x = nums[k];
      if (!umap1.count(x)) {
        umap1[x] = k;
      } else if (!umap2.count(x)) {
        umap2[x] = k;
      } else {
        int i = umap1[x], j = umap2[x];
        res = min(res, abs(i - j) + abs(j - k) + abs(k - i));
        umap1[x] = j;
        umap2[x] = k;
      }
    }

    return res == INT_MAX / 2 ? -1 : res;
  }
};