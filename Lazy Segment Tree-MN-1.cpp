// Lazy Segment Tree：查詢區間 min/max，區間更新加值
class LazySegmentTree {
public:
  int n;
  vector<pair<int, int>> tree; // min, max
  vector<int> lazy;

  LazySegmentTree(int n, const vector<int> &arr) : n(n) {
    tree.assign(4 * n, {INT_MAX, INT_MIN});
    lazy.assign(4 * n, 0);
    build(1, 0, n - 1, arr);
  }

  void update(int ql, int qr, int v) { update(1, 0, n - 1, ql, qr, v); }

  pair<int, int> query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }

private:
  void build(int p, int l, int r, const vector<int> &arr) {
    if (l == r) {
      tree[p] = {arr[l], arr[l]};
      return;
    }
    int m = (l + r) / 2;
    build(p << 1, l, m, arr);
    build(p << 1 | 1, m + 1, r, arr);
    pull(p);
  }

  void pull(int p) {
    tree[p].first = min(tree[p << 1].first, tree[p << 1 | 1].first);    // min
    tree[p].second = max(tree[p << 1].second, tree[p << 1 | 1].second); // max
  }

  void apply(int p, int l, int r, int v) {
    tree[p].first += v;
    tree[p].second += v;
    lazy[p] += v;
  }

  void push(int p, int l, int r) {
    if (lazy[p] == 0 || l == r)
      return;
    int m = (l + r) / 2;
    apply(p << 1, l, m, lazy[p]);
    apply(p << 1 | 1, m + 1, r, lazy[p]);
    lazy[p] = 0;
  }

  void update(int p, int l, int r, int ql, int qr, int v) {
    if (qr < l || r < ql)
      return; // no overlap
    if (ql <= l && r <= qr) {
      apply(p, l, r, v);
      return;
    }
    push(p, l, r);
    int m = (l + r) / 2;
    update(p << 1, l, m, ql, qr, v);
    update(p << 1 | 1, m + 1, r, ql, qr, v);
    pull(p);
  }

  pair<int, int> query(int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return {INT_MAX, INT_MIN}; // no overlap
    if (ql <= l && r <= qr)
      return tree[p];
    push(p, l, r);
    int m = (l + r) / 2;
    auto L = query(p << 1, l, m, ql, qr);
    auto R = query(p << 1 | 1, m + 1, r, ql, qr);
    return {min(L.first, R.first), max(L.second, R.second)};
  }
};
