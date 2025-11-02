class Solution {
public:
  long long minimumTime(vector<int> &d, vector<int> &r) {
    long long a = r[0], b = r[1], c = 1LL * a * b / gcd(a, b);
    long long lo = d[0] + d[1], hi = LONG_MAX;
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (d[0] + d[1] > mid - mid / c || d[0] > mid - mid / a ||
          d[1] > mid - mid / b)
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo;
  }
};