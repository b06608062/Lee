// mark
// 1973
// 二分搜尋 + 數學
// X = 1 可 2 不可
// Y = 2 可 1 不可
// Z = 1 2 都可
// d1 + d2 <= X + Y + Z
// d1 <= X + Z
// d2 <= Y + Z
class Solution {
public:
  long long d1, d2, r1, r2, lcm;
  long long minimumTime(vector<int> &d, vector<int> &r) {
    d1 = d[0], d2 = d[1];
    r1 = r[0], r2 = r[1];
    lcm = r1 * r2 / gcd(r1, r2);
    long long lo = d1 + d2, hi = LLONG_MAX;
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (!valid(mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo;
  }

  bool valid(long long T) {
    long long tAvl = T - (T / lcm);
    return (d1 + d2 <= tAvl) && (d1 <= T - (T / r1)) && (d2 <= T - (T / r2));
  }
};