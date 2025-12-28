class Solution {
public:
  long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                        int need2) {
    if (costBoth > cost1 + cost2)
      return 1ll * cost1 * need1 + 1ll * cost2 * need2;
    else if (need1 > need2)
      return 1ll * costBoth * need2 +
             1ll * min(costBoth, cost1) * (need1 - need2);
    else
      return 1ll * costBoth * need1 +
             1ll * min(costBoth, cost2) * (need2 - need1);
  }
};