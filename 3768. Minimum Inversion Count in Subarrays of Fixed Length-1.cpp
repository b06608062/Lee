// mark
// 2158
// 定長滑窗 + Fenwick Tree 維護出現頻率前綴和 + 值域離散化 + 逆序對計數
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

class Solution {
public:
  long long minInversionCount(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> sorted(nums.begin(), nums.end());
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    for (auto &x : nums)
      x = lower_bound(sorted.begin(), sorted.end(), x) - sorted.begin() + 1;

    FenwickTree ft(sorted.size());

    long long res = LLONG_MAX, inv = 0;
    for (int i = 0; i < n; ++i) {
      if (i - k >= 0) {
        int out = nums[i - k];
        inv -= ft.query(out - 1);
        ft.update(out, -1);
      }
      int in = nums[i];
      ft.update(in, 1);
      inv += min(i + 1, k) - ft.query(in);

      if (i >= k - 1)
        res = min(res, inv);
    }

    return res;
  }
};