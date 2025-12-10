// mark
// Fenwick Tree (Binary Indexed Tree) 入門
struct FenwickTree {
  vector<int> bit;
  FenwickTree(int n) : bit(n + 1, 0) {}

  void update(int i, int delta) {
    while (i < bit.size()) {
      bit[i] += delta;
      i += lowbit(i);
    }
  }

  int query(int i) {
    int sum = 0;
    while (i > 0) {
      sum += bit[i];
      i -= lowbit(i);
    }
    return sum;
  }

  int lowbit(int x) { return x & (-x); }
};

class NumArray {
public:
  FenwickTree ft;
  vector<int> a;
  int n;
  NumArray(vector<int> &nums) : ft(nums.size()), a(nums), n(nums.size()) {
    for (int i = 0; i < n; ++i)
      ft.update(i + 1, nums[i]);
  }

  void update(int index, int val) {
    int old = a[index];
    int delta = val - old;
    a[index] = val;
    ft.update(index + 1, delta);
  }

  int sumRange(int left, int right) {
    return ft.query(right + 1) - ft.query(left);
  }
};
