// mark
// ???
// 排序後枚舉右 + 線段樹

class Solution {
public:
  vector<int> tree;
  void pull(int p) { tree[p] = max(tree[p << 1], tree[p << 1 | 1]); }
  void update(int p, int l, int r, int q, int cap) {
    if (l == r) {
      tree[p] = max(tree[p], cap);
      return;
    }
    int m = (l + r) / 2;
    if (q <= m)
      update(p << 1, l, m, q, cap);
    else
      update(p << 1 | 1, m + 1, r, q, cap);
    pull(p);
  }
  int query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
      return tree[p];
    }
    int m = (l + r) / 2;
    if (qr <= m)
      return query(p << 1, l, m, ql, qr);
    else if (ql > m)
      return query(p << 1 | 1, m + 1, r, ql, qr);
    return max(query(p << 1, l, m, ql, qr),
               query(p << 1 | 1, m + 1, r, ql, qr));
  }
  int maxCapacity(vector<int> &costs, vector<int> &capacity, int budget) {
    int n = costs.size();

    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
      if (costs[i] < budget) {
        arr.push_back({costs[i], capacity[i]});
      }
    }
    sort(arr.begin(), arr.end());

    tree.resize((budget + 1) << 2);
    int res = 0;
    for (auto &[cost, cap] : arr) {
      int t = budget - cost - 1;
      res = max(res, cap + query(1, 0, budget, 0, t));
      update(1, 0, budget, cost, cap);
    }

    return res;
  }
};