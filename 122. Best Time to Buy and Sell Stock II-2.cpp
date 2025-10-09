class Solution {
public:
  int maxProfit(vector<int> &prices) {
    int hold = -1e4, rest = 0;
    for (auto x : prices) {
      int prevHold = hold;
      hold = max(hold, rest - x);
      rest = max(rest, prevHold + x);
    }

    return rest;
  }
};