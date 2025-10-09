class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int res = numBottles, empty = numBottles;
    while (empty >= numExchange) {
      res += empty / numExchange;
      empty = (empty % numExchange) + (empty / numExchange);
    }

    return res;
  }
};