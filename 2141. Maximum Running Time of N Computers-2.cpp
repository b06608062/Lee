// mark
// 2265
// binary search + greedy
class Solution {
public:
  long long maxRunTime(int n, vector<int> &batteries) {
    long long sum = accumulate(batteries.begin(), batteries.end(), 0ll);

    long long lo = 1, hi = (sum / n) + 1;
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (valid(n, batteries, mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo - 1;
  }

  bool valid(int n, vector<int> &batteries, long long T) {
    long long total = 0;
    for (long long b : batteries)
      total += min(b, T);
    return n * T <= total;
  }
};