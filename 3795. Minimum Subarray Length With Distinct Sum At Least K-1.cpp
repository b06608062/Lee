class Solution {
public:
  int minLength(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> umap;
    int l = 0, r = 0, cur = 0, res = n + 1;
    while (r < n) {
      int x = nums[r];
      if (++umap[x] == 1)
        cur += x;
      while (cur >= k) {
        res = min(res, r - l + 1);
        int y = nums[l++];
        if (--umap[y] == 0)
          cur -= y;
      }
      r++;
    }

    return res == n + 1 ? -1 : res;
  }
};