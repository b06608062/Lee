// Lazy Segment Tree 查詢區間和，區間更新加值與賦值
class LazySegmentTree {
public:
  int n;
  vector<long long> tree;      // sum
  vector<long long> addVal;    // pending add
  vector<long long> assignVal; // pending assign value
  vector<bool> hasAssign;      // whether assignVal is active

  LazySegmentTree(int n, const vector<int> &arr) : n(n) {
    tree.assign(4 * n, 0);
    addVal.assign(4 * n, 0);
    assignVal.assign(4 * n, 0);
    hasAssign.assign(4 * n, false);
    build(1, 0, n - 1, arr);
  }

  void add(int ql, int qr, long long v) { add(1, 0, n - 1, ql, qr, v); }

  void assign(int ql, int qr, long long v) { assign(1, 0, n - 1, ql, qr, v); }

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

  void pull(int p) { tree[p] = tree[p << 1] + tree[p << 1 | 1]; }

  void apply_assign(int p, int l, int r, long long v) {
    tree[p] = v * (r - l + 1);
    hasAssign[p] = true;
    assignVal[p] = v;
    addVal[p] = 0;
  }

  void apply_add(int p, int l, int r, long long v) {
    tree[p] += v * (r - l + 1);
    if (hasAssign[p])
      assignVal[p] += v;
    else
      addVal[p] += v;
  }

  void push(int p, int l, int r) {
    if (l == r)
      return;
    int m = (l + r) / 2;

    if (hasAssign[p]) {
      apply_assign(p << 1, l, m, assignVal[p]);
      apply_assign(p << 1 | 1, m + 1, r, assignVal[p]);
      hasAssign[p] = false;
    }

    if (addVal[p] != 0) {
      apply_add(p << 1, l, m, addVal[p]);
      apply_add(p << 1 | 1, m + 1, r, addVal[p]);
      addVal[p] = 0;
    }
  }

  void assign(int p, int l, int r, int ql, int qr, long long v) {
    if (qr < l || r < ql)
      return;
    if (ql <= l && r <= qr) {
      apply_assign(p, l, r, v);
      return;
    }
    push(p, l, r);
    int m = (l + r) / 2;
    assign(p << 1, l, m, ql, qr, v);
    assign(p << 1 | 1, m + 1, r, ql, qr, v);
    pull(p);
  }

  void add(int p, int l, int r, int ql, int qr, long long v) {
    if (qr < l || r < ql)
      return;
    if (ql <= l && r <= qr) {
      apply_add(p, l, r, v);
      return;
    }
    push(p, l, r);
    int m = (l + r) / 2;
    add(p << 1, l, m, ql, qr, v);
    add(p << 1 | 1, m + 1, r, ql, qr, v);
    pull(p);
  }

  long long query(int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return 0;
    if (ql <= l && r <= qr)
      return tree[p];
    push(p, l, r);
    int m = (l + r) / 2;
    return query(p << 1, l, m, ql, qr) + query(p << 1 | 1, m + 1, r, ql, qr);
  }
};
