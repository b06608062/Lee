class Solution {
public:
  int minDays(vector<int> &bloomDay, int m, int k) {
    int n = bloomDay.size();
    if (1LL * m * k > n)
      return -1;

    auto ckeck = [&](int D) -> bool {
      int cnt = 0, group = 0;
      for (auto x : bloomDay)
        if (x <= D) {
          cnt++;
          if (cnt == k) {
            cnt = 0;
            group++;
          }
        } else
          cnt = 0;
      return group >= m;
    };

    int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end());
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (!ckeck(mid))
        l = mid + 1;
      else
        r = mid;
    }

    return l;
  }
};