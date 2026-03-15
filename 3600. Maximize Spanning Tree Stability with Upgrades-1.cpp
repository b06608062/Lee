// mark
// 2301
// SPT + DSU + 二分答案
// 1. 先二分答案 x，然後檢查能不能達成 x 的穩定度
// 2. 檢查的過程中，先把所有必須的邊加入 DSU，如果有必須的邊不夠穩定或是形成
// cycle 就直接回傳 false
// 3. 接著把所有免費的可選邊加入
// DSU，這些邊不會影響穩定度，所以不管它們的穩定度如何都加入
// 4. 最後把所有弱的可選邊加入 DSU，這些邊會消耗升級次數，所以如果加入了就把 k
// 減 1，如果 k < 0 就回傳 false
// 5. 最後檢查 DSU 的 component 數量，如果是 1 就回傳 true，否則回傳 false

struct DSU {
  vector<int> p, sz;
  int components;
  DSU(int n) : p(n), sz(n, 1), components(n) { iota(p.begin(), p.end(), 0); }
  int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
  bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b)
      return false;
    if (sz[a] < sz[b])
      swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
    components--;
    return true;
  }
};

class Solution {
public:
  bool canAchieve(int n, vector<vector<int>> &edges, int k, int x) {
    DSU dsu(n);

    // 1. Mandatory edges must be included
    for (auto &e : edges) {
      int u = e[0], v = e[1], s = e[2], must = e[3];
      if (must == 1) {
        if (s < x)
          return false; // mandatory edge too weak
        if (!dsu.unite(u, v))
          return false; // mandatory cycle
      }
    }

    // 2. Use all free optional edges
    for (auto &e : edges) {
      int u = e[0], v = e[1], s = e[2], must = e[3];
      if (must == 0 && s >= x)
        dsu.unite(u, v);
    }

    // 3. Use up to k weak optional edges
    for (auto &e : edges) {
      int u = e[0], v = e[1], s = e[2], must = e[3];
      if (must == 0 && s < x && 2 * s >= x)
        if (dsu.unite(u, v))
          if (--k < 0)
            return false;
    }

    return dsu.components == 1;
  }

  int maxStability(int n, vector<vector<int>> &edges, int k) {
    int lo = 0, hi = 1e5 * 2 + 1;
    while (lo < hi) {
      int mid = lo + (hi - lo) / 2;
      if (canAchieve(n, edges, k, mid))
        lo = mid + 1;
      else
        hi = mid;
    }
    return lo - 1;
  }
};