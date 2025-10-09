class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    bitset<3001> dp;

    dp[0] = 1;
    for (int x : stones)
      dp |= dp << x;

    for (int i = sum / 2; i >= 0; --i)
      if (dp[i])
        return sum - 2 * i;

    return -1;
  }
};