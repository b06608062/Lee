// mark
// 線段樹二分 + 特殊節點資訊
class SegmentTree {
  struct T {
    int lc, rc, cnt;
  };

  int n;
  vector<T> tree;
  T merge(const T &l, const T &r) const {
    return {l.lc, r.rc, l.cnt + r.cnt + (l.rc == r.lc)};
  }

  void pull(int p) { tree[p] = merge(tree[p << 1], tree[p << 1 | 1]); }

  void build(int p, int l, int r, const string &s) {
    if (l == r) {
      tree[p] = {s[l] - 'A', s[r] - 'A', 0};
      return;
    }
    int m = (l + r) / 2;
    build(p << 1, l, m, s);
    build(p << 1 | 1, m + 1, r, s);
    pull(p);
  }

  void flip(int p, int l, int r, int i) {
    if (l == r) {
      tree[p].lc ^= 1;
      tree[p].rc ^= 1;
      return;
    }
    int m = (l + r) / 2;
    if (i <= m)
      flip(p << 1, l, m, i);
    else
      flip(p << 1 | 1, m + 1, r, i);
    pull(p);
  }

  T query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
      return tree[p];
    int m = (l + r) / 2;
    if (qr <= m)
      return query(p << 1, l, m, ql, qr);
    else if (ql > m)
      return query(p << 1 | 1, m + 1, r, ql, qr);
    return merge(query(p << 1, l, m, ql, qr),
                 query(p << 1 | 1, m + 1, r, ql, qr));
  }

public:
  SegmentTree(const string &s) : n(s.size()) {
    tree.resize(4 * n);
    build(1, 0, n - 1, s);
  }

  void flip(int i) { flip(1, 0, n - 1, i); }

  int query(int ql, int qr) { return query(1, 0, n - 1, ql, qr).cnt; }
};

class Solution {
public:
  vector<int> minDeletions(string s, vector<vector<int>> &queries) {
    SegmentTree t(s);
    vector<int> res;
    for (auto &q : queries)
      if (q[0] == 1)
        t.flip(q[1]);
      else
        res.push_back(t.query(q[1], q[2]));

    return res;
  }
};