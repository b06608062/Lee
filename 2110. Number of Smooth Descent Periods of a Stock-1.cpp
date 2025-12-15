class Solution {
public:
  long long getDescentPeriods(vector<int> &prices) {
    int n = prices.size();

    long long res = 0;
    int l = 0, r = 0;
    while (r < n) {
      if (r > 0 && prices[r] + 1 != prices[r - 1])
        l = r;
      res += r - l + 1;
      r++;
    }

    return res;
  }
};