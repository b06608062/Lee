// mark
// 2469
// Segment Tree Array + 最大值最小值區間查詢 + 最大值-最小值貪心取前 k 大
class Solution {
public:
  vector<pair<int, int>> tree; // min, max
  void build(vector<int> &nums, int p, int l, int r) {
    if (l == r) {
      tree[p] = {nums[l], nums[l]};
      return;
    }

    int m = l + (r - l) / 2;
    build(nums, p << 1, l, m);
    build(nums, p << 1 | 1, m + 1, r);
    tree[p] = {min(tree[p << 1].first, tree[p << 1 | 1].first),
               max(tree[p << 1].second, tree[p << 1 | 1].second)};
  }

  void update(int p, int l, int r, int i, int val) {
    if (l == r) {
      tree[p] = {val, val};
      return;
    }

    int m = l + (r - l) / 2;
    if (i <= m)
      update(p << 1, l, m, i, val);
    else
      update(p << 1 | 1, m + 1, r, i, val);
    tree[p] = {min(tree[p << 1].first, tree[p << 1 | 1].first),
               max(tree[p << 1].second, tree[p << 1 | 1].second)};
  }

  pair<int, int> query(int p, int l, int r, int ql, int qr) {
    if (qr < l || ql > r)
      return {INT_MAX, INT_MIN};
    if (ql <= l && r <= qr)
      return tree[p];
    int m = l + (r - l) / 2;
    auto left = query(p << 1, l, m, ql, qr);
    auto right = query(p << 1 | 1, m + 1, r, ql, qr);
    return {min(left.first, right.first), max(left.second, right.second)};
  }

  long long maxTotalValue(vector<int> &nums, int k) {
    int n = nums.size();
    tree.assign(4 * n, {INT_MAX, INT_MIN});
    build(nums, 1, 0, n - 1);

    // max heap
    auto comp = [](auto &a, auto &b) { return get<0>(a) < get<0>(b); };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                   decltype(comp)>
        pq(comp); // val, l, r
    set<pair<int, int>> sset;

    sset.insert({0, n - 1});
    auto maxVal = query(1, 0, n - 1, 0, n - 1);
    pq.push({maxVal.second - maxVal.first, 0, n - 1});

    long long res = 0;
    while (!pq.empty() && k--) {
      auto [val, l, r] = pq.top();
      pq.pop();
      res += val;
      if (l < r) {
        if (!sset.count({l + 1, r})) {
          sset.insert({l + 1, r});
          auto left = query(1, 0, n - 1, l + 1, r);
          pq.push({left.second - left.first, l + 1, r});
        }
        if (!sset.count({l, r - 1})) {
          sset.insert({l, r - 1});
          auto right = query(1, 0, n - 1, l, r - 1);
          pq.push({right.second - right.first, l, r - 1});
        }
      }
    }

    return res;
  }
};