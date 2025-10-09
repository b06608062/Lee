class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int res = 0;
    while (numBottles >= numExchange) {
      int k = numBottles / numExchange;
      res += k * numExchange;
      numBottles = k + (numBottles % numExchange);
    }

    return res + numBottles;
  }
};