// mark
// 2236
// 值域離散化 + Lazy Segment Tree + 掃描線
// 矩形面積並集
class SegmentTree {
public:
  struct Node {
    int l, r;
    int min_cover_len = 0;
    int min_cover = 0;
    int todo = 0;
  };
  vector<Node> tree;
  SegmentTree(vector<int> &xs) {
    int n = xs.size() - 1;
    tree.resize(n * 4);
    build(xs, 1, 0, n - 1);
  }

  void update(int l, int r, int v) { update(1, l, r, v); }

  int get_len() { return tree[1].min_cover ? 0 : tree[1].min_cover_len; }

private:
  void build(vector<int> &xs, int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    if (l == r) {
      tree[p].min_cover_len = xs[l + 1] - xs[l];
      return;
    }
    int m = (l + r) / 2;
    build(xs, p << 1, l, m);
    build(xs, p << 1 | 1, m + 1, r);
    pull(p);
  }

  void pull(int p) {
    auto &lc = tree[p << 1];
    auto &rc = tree[p << 1 | 1];
    int mn = min(lc.min_cover, rc.min_cover);
    tree[p].min_cover = mn;
    tree[p].min_cover_len = (lc.min_cover == mn ? lc.min_cover_len : 0) +
                            (rc.min_cover == mn ? rc.min_cover_len : 0);
  }

  void lazy(int p, int v) {
    tree[p].min_cover += v;
    tree[p].todo += v;
  }

  void push(int p) {
    int &v = tree[p].todo;
    if (v != 0) {
      lazy(p << 1, v);
      lazy(p << 1 | 1, v);
      v = 0;
    }
  }

  void update(int p, int l, int r, int v) {
    if (l <= tree[p].l && tree[p].r <= r) {
      lazy(p, v);
      return;
    }
    push(p);
    int m = (tree[p].l + tree[p].r) / 2;
    if (l <= m) {
      update(p << 1, l, r, v);
    }
    if (m < r) {
      update(p << 1 | 1, l, r, v);
    }
    pull(p);
  }
};

struct Event {
  int y, lx, rx, delta;
};

class Solution {
public:
  int rectangleArea(vector<vector<int>> &rectangles) {
    const int MOD = 1e9 + 7;
    vector<int> xs;
    vector<Event> evs;
    for (auto &r : rectangles) {
      int lx = r[0], rx = r[2];
      xs.push_back(lx);
      xs.push_back(rx);
      evs.emplace_back(r[1], lx, rx, 1);
      evs.emplace_back(r[3], lx, rx, -1);
    }

    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    SegmentTree t(xs);

    sort(evs.begin(), evs.end(),
         [](const Event &a, const Event &b) { return a.y < b.y; });

    long long res = 0;
    for (int i = 0; i + 1 < evs.size(); ++i) {
      auto &[y, lx, rx, delta] = evs[i];
      int l = lower_bound(xs.begin(), xs.end(), lx) - xs.begin();
      int r = lower_bound(xs.begin(), xs.end(), rx) - xs.begin() - 1;
      t.update(l, r, delta);
      int sum_len = xs.back() - xs[0] - t.get_len();
      res += 1ll * sum_len * (evs[i + 1].y - y);
    }
    return res % MOD;
  }
};