class Solution {
public:
  long long numGoodSubarrays(vector<int> &nums, int k) {
    int n = nums.size();

    unordered_map<int, int> umap;
    vector<int> temp;
    temp.push_back(0);

    int l = 0, r = 0, cur = 0;
    long long res = 0;
    while (r < n) {
      while (r + 1 < n && nums[r] == nums[r + 1])
        r++;

      for (int i = l; i < r; ++i) {
        cur += nums[i];
        cur %= k;
        if (cur < 0)
          cur += k;
        res += umap[cur];
        temp.push_back(cur);
      }

      for (auto x : temp)
        umap[x]++;

      cur += nums[r];
      cur %= k;
      if (cur < 0)
        cur += k;
      res += umap[cur];
      temp.clear();
      temp.push_back(cur);
      r++;
      l = r;
    }

    return res;
  }
};