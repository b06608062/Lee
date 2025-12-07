class Solution {
public:
  vector<long long> countBlackBlocks(int m, int n,
                                     vector<vector<int>> &coordinates) {
    map<pair<int, int>, int> mmap;
    for (auto &c : coordinates) {
      int x = c[0], y = c[1];
      mmap[{x - 1, y - 1}]++;
      mmap[{x - 1, y}]++;
      mmap[{x, y - 1}]++;
      mmap[{x, y}]++;
    }

    vector<long long> res(5, 0);
    for (auto &[k, v] : mmap) {
      auto [x, y] = k;
      if (x >= 0 && x < m - 1 && y >= 0 && y < n - 1)
        res[v]++;
    }

    res[0] =
        1ll * (m - 1) * (n - 1) - accumulate(res.begin() + 1, res.end(), 0);

    return res;
  }
};