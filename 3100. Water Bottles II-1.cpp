class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int empty = numBottles, res = numBottles;
    while (empty >= numExchange) {
      empty -= numExchange++;
      res++;
      empty++;
    }

    return res;
  }
};