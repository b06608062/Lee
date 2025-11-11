class Solution {
public:
  int n;
  vector<pair<int, int>> tree; // minVal, idx
  int minOperations(vector<int> &nums) {
    n = nums.size();
    tree.assign(4 * n, {INT_MAX, -1});
    build(1, 0, n - 1, nums);

    return solve(0, n - 1, 0);
  }

  int solve(int l, int r, int base) {
    if (l > r)
      return 0;
    auto [minVal, idx] = query(1, 0, n - 1, l, r);
    int cost = minVal > base ? 1 : 0;
    return cost + solve(l, idx - 1, minVal) + solve(idx + 1, r, minVal);
  }

private:
  void build(int p, int l, int r, vector<int> &nums) {
    if (l == r) {
      tree[p] = {nums[l], l};
      return;
    }

    int m = (l + r) / 2;
    build(p << 1, l, m, nums);
    build(p << 1 | 1, m + 1, r, nums);
    tree[p] = min(tree[p << 1], tree[p << 1 | 1]);
  }

  pair<int, int> query(int p, int l, int r, int ql, int qr) {
    if (qr < l || r < ql)
      return {INT_MAX, -1};
    if (ql <= l && r <= qr)
      return tree[p];

    int m = (l + r) / 2;
    return min(query(p << 1, l, m, ql, qr),
               query(p << 1 | 1, m + 1, r, ql, qr));
  }
};