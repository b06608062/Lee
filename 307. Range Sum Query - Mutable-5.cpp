class LazySegmentTree {
public:
  int n;
  vector<long long> tree; // sum
  vector<long long> lazy;

  LazySegmentTree(int n, const vector<int> &arr) : n(n) {
    tree.assign(4 * n, 0);
    lazy.assign(4 * n, 0);
    build(1, 0, n - 1, arr);
  }

  void update(int ql, int qr, long long v) { update(1, 0, n - 1, ql, qr, v); }

  long long query(int ql, int qr) { return query(1, 0, n - 1, ql, qr); }

private:
  void build(int p, int l, int r, const vector<int> &arr) {
    if (l == r) {
      tree[p] = arr[l];
      return;
    }
    int m = (l + r) / 2;
    build(p << 1, l, m, arr);
    build(p << 1 | 1, m + 1, r, arr);
    pull(p);
  }

  void apply(int p, int l, int r, long long v) {
    tree[p] += v * (r - l + 1);
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

  void pull(int p) { tree[p] = tree[p << 1] + tree[p << 1 | 1]; }

  void update(int p, int l, int r, int ql, int qr, long long v) {
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

  long long query(int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return 0; // no overlap
    if (ql <= l && r <= qr)
      return tree[p];
    push(p, l, r);
    int m = (l + r) / 2;
    return query(p << 1, l, m, ql, qr) + query(p << 1 | 1, m + 1, r, ql, qr);
  }
};

class NumArray {
public:
  LazySegmentTree t;
  vector<int> a;
  int n;
  NumArray(vector<int> &nums) : t(nums.size(), nums), a(nums), n(nums.size()) {}

  void update(int index, int val) {
    int old = a[index];
    int delta = val - old;
    a[index] = val;
    t.update(index, index, delta);
  }

  int sumRange(int left, int right) { return t.query(left, right); }
};
