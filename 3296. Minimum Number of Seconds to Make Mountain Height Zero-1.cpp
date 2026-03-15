// mark
// 1695
// 先二分答案 T，然後對每個工人二分他能夠挖多少高度，最後加總看看能不能挖完山

class Solution {
public:
  long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
    long long H = mountainHeight;
    long long mn = *min_element(workerTimes.begin(), workerTimes.end());
    long long lo = 1, hi = 1ll * mn * H * (H + 1) / 2;
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (!helper(mountainHeight, workerTimes, mid))
        lo = mid + 1;
      else
        hi = mid;
    }
    return lo;
  }

  bool helper(int mountainHeight, vector<int> &workerTimes, long long T) {
    long long total = 0;
    for (long long t : workerTimes) {
      long long lo = 1, hi = mountainHeight + 1;
      while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        long long cost = t * mid * (mid + 1) / 2;
        if (cost <= T)
          lo = mid + 1;
        else
          hi = mid;
      }
      total += (lo - 1);
    }
    return total >= mountainHeight;
  }
};