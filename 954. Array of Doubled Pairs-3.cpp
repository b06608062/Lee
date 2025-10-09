class Solution {
public:
  bool canReorderDoubled(vector<int> &arr) {
    sort(arr.begin(), arr.end(),
         [](auto &a, auto &b) { return abs(a) < abs(b); });

    unordered_map<int, int> umap;
    for (auto x : arr)
      umap[x]++;

    if (umap[0] % 2)
      return false;

    for (auto x : arr) {
      int count = umap[x];
      if (count == 0 || x == 0)
        continue;
      umap[x] = 0;
      umap[2 * x] -= count;
      if (umap[2 * x] < 0)
        return false;
    }

    return true;
  }
};