// mark
// 2202
// 最長平衡子字串 + 多維前綴差分 + 哈希表
template <class T1, class T2> struct PairHash {
  size_t operator()(const pair<T1, T2> &p) const noexcept {
    size_t h1 = hash<T1>{}(p.first);
    size_t h2 = hash<T2>{}(p.second);
    size_t h = h1;
    h ^= h2 + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
    return h;
  }
};

class Solution {
public:
  int longestBalanced(string s) {
    int n = s.size();

    // 單一字元
    int start = 0, res = 1;
    for (int i = 1; i < n; ++i) {
      if (s[i] != s[i - 1])
        start = i;
      res = max(res, i - start + 1);
    }

    // 兩字元
    auto findTwo = [&](char x, char y, char z) -> void {
      int i = 0;
      while (i < n) {
        unordered_map<int, int> umap = {{0, i - 1}};
        int diff = 0;
        while (i < n && s[i] != z) {
          diff += s[i] == x ? 1 : -1;
          if (umap.count(diff))
            res = max(res, i - umap[diff]);
          else
            umap[diff] = i;
          i++;
        }
        i++;
      }
    };

    auto findTwo = [&](char x, char y, char z) -> void {
      unordered_map<pair<int, int>, int, PairHash<int, int>> umap;
      int diff = 0, cntZ = 0;
      umap[{0, 0}] = -1;
      for (int i = 0; i < n; ++i) {
        if (s[i] == x)
          diff++;
        else if (s[i] == y)
          diff--;
        else if (s[i] == z)
          cntZ++;
        if (umap.count({diff, cntZ}))
          res = max(res, i - umap[{diff, cntZ}]);
        else
          umap[{diff, cntZ}] = i;
      }
    };

    findTwo('a', 'b', 'c');
    findTwo('a', 'c', 'b');
    findTwo('b', 'c', 'a');

    // 三字元
    unordered_map<pair<int, int>, int, PairHash<int, int>> umap{{{0, 0}, -1}};
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      cnt[s[i]]++;
      pair<int, int> p = {cnt['a'] - cnt['b'], cnt['b'] - cnt['c']};
      if (umap.count(p))
        res = max(res, i - umap[p]);
      else
        umap[p] = i;
    }

    return res;
  }
};