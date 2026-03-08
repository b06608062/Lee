class SegmentTree {
public:
  vector<int> tree;
  int n;
  SegmentTree(int sz) {
    n = sz;
    tree.assign(n * 4, 0);
  }
  void update(int p, int l, int r, int i, int val) {
    if (l == r) {
      tree[p] = max(tree[p], val);
      return;
    }
    int mid = l + (r - l) / 2;
    if (i <= mid)
      update(p << 1, l, mid, i, val);
    else
      update(p << 1 | 1, mid + 1, r, i, val);
    tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
  }

  int query(int p, int l, int r, int ql, int qr) {
    if (ql > qr || ql > r || qr < l)
      return 0;
    if (ql <= l && r <= qr)
      return tree[p];
    int mid = l + (r - l) / 2;
    return max(query(p << 1, l, mid, ql, qr),
               query(p << 1 | 1, mid + 1, r, ql, qr));
  }
};

class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() == 0)
      return 0;
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    int m = sorted.size();
    SegmentTree st(m);
    int res = 0;
    for (auto x : nums) {
      int i = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin();
      int prev_mx = st.query(1, 0, m - 1, 0, i - 1);
      st.update(1, 0, m - 1, i, prev_mx + 1);
      res = max(res, prev_mx + 1);
    }
    return res;
  }
};
