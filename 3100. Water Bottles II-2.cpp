/*
Let:
b = numBottles
e = numExchange
t = number of exchanges you can perform
Each exchange costs one more empty bottle than the previous:
costs per exchange: e, e+1, …, e+(t-1)
Total needed empties:
needed = te + t(t-1)/2
Before paying for the t-th exchange, you have only the bottles from the first
(t-1) exchanges: have = b + (t - 1) (not b + t, because the empty from the t-th
bottle appears only after you complete that exchange) Feasibility to do t
exchanges: b + (t - 1) >= te + t(t - 1)/2 Rearrange to a quadratic inequality:
t^2 + (2e - 3)t + 2(1 - b) <= 0
*/

class Solution {
public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int a = 1, b = 2 * numExchange - 3, c = 2 * (1 - numBottles);
    int delta = b * b - 4 * a * c;
    // if (delta < 0)
    //   return numBottles;

    double t = (-b + sqrt(delta)) / (2 * a);
    // if (t < 0.0)
    //   return numBottles;

    return numBottles + (int)t;
  }
};