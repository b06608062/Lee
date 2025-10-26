class Solution {
public:
  long long repairCars(vector<int> &ranks, int cars) {

    auto check = [&](long long T) -> bool {
      long long cnt = 0;
      for (auto r : ranks)
        cnt += sqrt((double)T / r);
      return cnt >= cars;
    };

    long long lo = 1, hi = LONG_MAX;
    while (lo < hi) {
      long long mid = lo + (hi - lo) / 2;
      if (!check(mid))
        lo = mid + 1;
      else
        hi = mid;
    }

    return lo;
  }
};