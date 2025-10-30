class NumArray {
public:
  int n;
  vector<int> tree;
  NumArray(vector<int> &nums) {
    n = nums.size();
    tree.assign(4 * n, 0);
    build(1, 0, n - 1, nums);
  }

  void update(int index, int val) { update(1, 0, n - 1, index, val); }

  int sumRange(int left, int right) { return query(1, 0, n - 1, left, right); }

private:
  void build(int p, int l, int r, vector<int> &nums) {
    if (l == r) {
      tree[p] = nums[l];
      return;
    }

    int m = (l + r) / 2;
    build(p << 1, l, m, nums);
    build(p << 1 | 1, m + 1, r, nums);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
  }

  void update(int p, int l, int r, int idx, int val) {
    if (l == r) {
      tree[p] = val;
      return;
    }

    int m = (l + r) / 2;
    if (idx <= m)
      update(p << 1, l, m, idx, val);
    else
      update(p << 1 | 1, m + 1, r, idx, val);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
  }

  int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return tree[p];
    int m = (l + r) / 2;
    int res = 0;
    if (ql <= m)
      res += query(p << 1, l, m, ql, qr);
    if (qr > m)
      res += query(p << 1 | 1, m + 1, r, ql, qr);
    return res;
  }
};
