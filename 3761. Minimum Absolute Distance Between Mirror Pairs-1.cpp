class Solution {
public:
  int minMirrorPairDistance(vector<int> &nums) {
    int n = nums.size();

    unordered_map<int, int> umap; // rx, idx
    int res = n;
    for (int j = 0; j < n; ++j) {
      int x = nums[j];
      if (umap.count(x) && j - umap[x] < res)
        res = j - umap[x];
      umap[reverse(x)] = j;
    }

    return res == n ? -1 : res;
  }

  int reverse(int x) {
    long long res = 0;
    while (x) {
      res = res * 10 + (x % 10);
      x /= 10;
    }
    return res;
  }
};