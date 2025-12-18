class Solution {
public:
  long long maxProfit(vector<int> &prices, vector<int> &strategy, int k) {
    int n = prices.size();

    vector<long long> prefix(n + 1, 0), suffix(n + 1, 0);

    for (int i = 1; i <= n; ++i)
      prefix[i] = prefix[i - 1] + prices[i - 1] * strategy[i - 1];
    for (int i = n - 1; i >= 0; --i)
      suffix[i] = suffix[i + 1] + prices[i] * strategy[i];

    long long res = prefix[n];

    long long cur = 0;
    int r = 0, hk = k / 2;
    while (r < n) {
      cur += prices[r];
      if (r - hk >= 0)
        cur -= prices[r - hk];
      if (r >= k - 1)
        res = max(res, prefix[r - k + 1] + cur + suffix[r + 1]);
      r++;
    }

    return res;
  }
};