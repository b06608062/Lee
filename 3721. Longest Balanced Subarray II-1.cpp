class LazySegmentTree {
public:
  int n;
  vector<pair<int, int>> tree; // min, max
  vector<int> lazy;

  LazySegmentTree(int n, pair<int, int> initVal = {0, 0}) : n(n) {
    tree.assign(4 * n, initVal);
    lazy.assign(4 * n, 0);
    build(1, 0, n - 1, initVal);
  }

  void update(int ql, int qr, int f) { update(1, 0, n - 1, ql, qr, f); }

  int find_first(int ql, int qr, int target) {
    return find_first(1, 0, n - 1, ql, qr, target);
  }

private:
  void build(int p, int l, int r, const pair<int, int> &initVal) {
    if (l == r) {
      tree[p] = initVal;
      return;
    }
    int m = (l + r) / 2;
    build(p << 1, l, m, initVal);
    build(p << 1 | 1, m + 1, r, initVal);
    pull(p);
  }

  void apply(int p, int l, int r, int v) {
    tree[p].first += v;
    tree[p].second += v;
    lazy[p] += v;
  }

  void push(int p, int l, int r) {
    if (lazy[p] == 0)
      return;
    int m = (l + r) / 2;
    apply(p << 1, l, m, lazy[p]);
    apply(p << 1 | 1, m + 1, r, lazy[p]);
    lazy[p] = 0;
  }

  void pull(int p) {
    tree[p].first = min(tree[p << 1].first, tree[p << 1 | 1].first);    // min
    tree[p].second = max(tree[p << 1].second, tree[p << 1 | 1].second); // max
  }

  void update(int p, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {
      apply(p, l, r, v);
      return;
    }
    push(p, l, r);
    int m = (l + r) / 2;
    if (ql <= m)
      update(p << 1, l, m, ql, qr, v);
    if (qr > m)
      update(p << 1 | 1, m + 1, r, ql, qr, v);
    pull(p);
  }

  int find_first(int p, int l, int r, int ql, int qr, int target) {
    if (qr < l || r < ql)
      return -1;
    if (target < tree[p].first || target > tree[p].second)
      return -1;
    if (l == r)
      return l;
    push(p, l, r);
    int m = (l + r) / 2;
    int res = find_first(p << 1, l, m, ql, qr, target);
    if (res == -1)
      res = find_first(p << 1 | 1, m + 1, r, ql, qr, target);
    return res;
  }
};

class Solution {
public:
  int longestBalanced(vector<int> &nums) {
    int n = nums.size();

    LazySegmentTree t(n + 1);
    unordered_map<int, int> umap;

    int res = 0, cur = 0;
    for (int i = 1; i <= n; ++i) {
      int x = nums[i - 1];
      int v = x % 2 ? 1 : -1;
      auto it = umap.find(x);
      if (it == umap.end()) {
        cur += v;
        t.update(i, n, v);
      } else {
        int j = it->second;
        t.update(j, i - 1, -v);
      }
      umap[x] = i;

      int j = t.find_first(0, i - 1 - res, cur);
      if (j >= 0)
        res = i - j;
    }

    return res;
  }
};
