class Solution {
public:
  int subarraysDivByK(vector<int> &nums, int k) {
    unordered_map<int, int> umap;
    umap[0] = 1;

    int curSum = 0, res = 0;
    for (int x : nums) {
      curSum += x;
      int mod = curSum % k;
      if (mod < 0)
        mod += k;
      res += umap[mod];
      umap[mod]++;
    }

    return res;
  }
};
