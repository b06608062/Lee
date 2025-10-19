class Solution {
public:
  int minOperations(vector<int> &nums) {
    unordered_map<int, int> umap;
    for (auto x : nums)
      umap[x]++;

    int res = 0;
    for (auto [x, cnt] : umap) {
      if (cnt % 3 == 0)
        res += cnt / 3;
      else if (cnt % 3 == 2)
        res += cnt / 3 + 1;
      else {
        cnt -= 4;
        res += 2;
        if (cnt < 0)
          return -1;
        res += cnt / 3;
      }
    }

    return res;
  }
};