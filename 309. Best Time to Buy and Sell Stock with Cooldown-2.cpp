class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int hold = -prices[0], rest = 0, sell = 0;
    for (int i = 1; i < prices.size(); ++i) {
      int x = prices[i];
      int prevHold = hold;
      hold = max(hold, rest - x);
      rest = max(rest, sell);
      sell = prevHold + x;
    }

    return max(rest, sell);
  }
};