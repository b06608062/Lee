class Solution {
public:
  int maxProfit(vector<int> &prices, int k = 1) {
    int hold = -prices[0], rest = 0;
    vector<int> cool(k, 0);

    for (int i = 1; i < prices.size(); ++i) {
      int x = prices[i];
      int prevHold = hold;
      hold = max(hold, rest - x);
      if (k > 0) {
        rest = max(rest, cool[k - 1]);
        for (int i = k - 1; i > 0; --i)
          cool[i] = cool[i - 1];
        cool[0] = prevHold + x;
      } else
        rest = max(rest, prevHold + x);
    }

    int res = rest;
    for (auto x : cool)
      res = max(res, x);

    return res;
  }
};