// mark
// 1974
// Greedy + DSU (next available dry day)
struct DSU {
  vector<int> p;
  DSU(vector<int> &rains, int n) : p(n + 1) {
    p[n] = n;
    for (int i = n - 1; i >= 0; --i)
      p[i] = rains[i] ? p[i + 1] : i;
  }

  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

  void uNext(int x) { p[x] = find(x + 1); }
};

class Solution {
public:
  vector<int> avoidFlood(vector<int> &rains) {
    int n = rains.size();

    DSU dsu(rains, n);
    unordered_map<int, int> umap; // r > 0, lakei -> idx

    vector<int> res(n, -1);
    for (int i = 0; i < n; ++i) {
      int r = rains[i];
      if (r == 0)
        res[i] = 1;
      else {
        // r > 0
        if (umap.count(r)) {
          int rIdx = umap[r];
          int dIdx = dsu.find(rIdx);
          if (dIdx > i)
            return {};
          res[dIdx] = r;
          dsu.uNext(dIdx);
        }
        umap[r] = i;
      }
    }

    return res;
  }
};