class Solution {
public:
  int sumDivisibleByK(vector<int> &nums, int k) {
    unordered_map<int, int> umap;
    for (auto x : nums)
      umap[x]++;

    int res = 0;
    for (auto [x, f] : umap)
      if (f % k == 0)
        res += x * f;

    return res;
  }
};