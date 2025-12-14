// mark
// Lazy Segment Tree：查詢區間最大值，區間統一更新為指定值 + 座標壓縮
// 經典掃描線題
class LazySegmentTree {
public:
  int n;
  vector<int> tree; // max
  vector<int> change;
  vector<bool> update;

  LazySegmentTree(int n) : n(n) {
    tree.assign(4 * n, 0);
    change.assign(4 * n, 0);
    update.assign(4 * n, false);
    build(1, 0, n - 1);
  }

  void assign(int ql, int qr, int v) { assign(1, 0, n - 1, ql, qr, v); }

  int query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }

private:
  void build(int p, int l, int r) {
    if (l == r) {
      tree[p] = 0;
      return;
    }
    int m = (l + r) / 2;
    build(p << 1, l, m);
    build(p << 1 | 1, m + 1, r);
    pull(p);
  }

  void pull(int p) { tree[p] = max(tree[p << 1], tree[p << 1 | 1]); }

  void apply(int p, int l, int r, int v) {
    tree[p] = v;
    change[p] = v;
    update[p] = true;
  }

  void push(int p, int l, int r) {
    if (!update[p] || l == r)
      return;
    int m = (l + r) / 2;
    apply(p << 1, l, m, change[p]);
    apply(p << 1 | 1, m + 1, r, change[p]);
    update[p] = false;
  }

  void assign(int p, int l, int r, int ql, int qr, int v) {
    if (qr < l || r < ql)
      return; // no overlap
    if (ql <= l && r <= qr) {
      apply(p, l, r, v);
      return;
    }
    push(p, l, r);
    int m = (l + r) / 2;
    assign(p << 1, l, m, ql, qr, v);
    assign(p << 1 | 1, m + 1, r, ql, qr, v);
    pull(p);
  }

  int query(int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return INT_MIN; // no overlap
    if (ql <= l && r <= qr)
      return tree[p];
    push(p, l, r);
    int m = (l + r) / 2;
    return max(query(p << 1, l, m, ql, qr),
               query(p << 1 | 1, m + 1, r, ql, qr));
  }
};

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    vector<int> sorted;
    for (auto &b : buildings) {
      sorted.push_back(b[0]);
      sorted.push_back(b[1]);
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    sort(buildings.begin(), buildings.end(),
         [](auto &a, auto &b) { return a[2] < b[2]; });

    int n = sorted.size();
    LazySegmentTree t(n);
    for (auto &b : buildings) {
      int l = b[0], r = b[1], h = b[2];
      l = lower_bound(sorted.begin(), sorted.end(), l) - sorted.begin();
      r = lower_bound(sorted.begin(), sorted.end(), r) - sorted.begin();
      t.assign(l, r - 1, h);
    }

    vector<vector<int>> res;
    int prevH = 0;
    for (int i = 0; i < n; ++i) {
      int curH = t.query(i, i);
      if (curH != prevH) {
        res.push_back({sorted[i], curH});
        prevH = curH;
      }
    }

    return res;
  }
};