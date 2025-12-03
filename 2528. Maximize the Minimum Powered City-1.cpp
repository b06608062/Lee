// mark
// 2236
// Binary Search + Diff Array + Greedy
class Solution {
public:
  long long maxPower(vector<int> &stations, int r, int k) {
    int n = stations.size();

    vector<long long> diff(n, 0);
    for (int i = 0; i < n; ++i) {
      int p = stations[i];
      diff[max(0, i - r)] += p;
      if (i + r + 1 < n)
        diff[i + r + 1] -= p;
    }

    auto valid = [&](long long P) {
      vector<long long> tempD = diff;
      long long tempK = k;
      long long cur = 0;
      for (int i = 0; i < n; ++i) {
        cur += tempD[i];
        if (cur < P) {
          long long toAdd = P - cur;
          if (tempK < toAdd)
            return false;
          cur += toAdd;
          tempK -= toAdd;
          if (i + r * 2 + 1 < n)
            tempD[i + r * 2 + 1] -= toAdd;
        }
      }

      return true;
    };

    long long lo = 1, hi = LONG_MAX;
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (valid(mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo - 1;
  }
};