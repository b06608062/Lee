class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int full = numBottles, empty = 0, res = 0;
    while (full + empty >= numExchange) {
      res += full;
      int prev = full;
      full = (full + empty) / numExchange;
      empty = (prev + empty) % numExchange;
    }
    res += full;

    return res;
  }
};