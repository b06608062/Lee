// mark
// 2090
// 差分前綴和 + Fenwick Tree（BIT）統計 <cur 的個數 + 座標轉換
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
  long long countMajoritySubarrays(vector<int> &nums, int target) {
    int n = nums.size();
    FenwickTree ft(n * 2 + 1);
    int offset = n + 1;
    ft.update(offset, 1);

    int cur = 0;
    long long res = 0;
    for (auto x : nums) {
      if (x == target) {
        cur += 1;
      } else {
        cur -= 1;
      }
      res += ft.query(cur + offset - 1);
      ft.update(cur + offset, 1);
    }

    return res;
  }
};