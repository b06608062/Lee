class Solution {
public:
  int minimumDistance(vector<int> &nums) {
    const int INF = INT_MAX / 2;
    int n = nums.size();

    unordered_map<int, vector<int>> umap;

    for (int i = 0; i < n; ++i)
      umap[nums[i]].push_back(i);

    int res = INF;
    for (auto &[_, v] : umap)
      if (v.size() >= 3) {
        int sz = v.size();
        for (int l = 2; l < sz; ++l) {
          int i = v[l - 2], j = v[l - 1], k = v[l];
          res = min(res, abs(i - j) + abs(j - k) + abs(k - i));
        }
      }

    return res == INF ? -1 : res;
  }
};