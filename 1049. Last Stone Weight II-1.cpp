class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    vector<int> dp(sum + 1, 0);

    dp[0] = 1;
    for (auto x : stones) {
      for (int i = sum; i - x >= 0; --i)
        if (dp[i - x])
          dp[i] = 1;
    }

    int A;
    for (int i = sum / 2; i >= 0; --i)
      if (dp[i]) {
        A = i;
        break;
      }

    // B >= A
    // B - A >= 0
    // B = sum - A
    // B - A = sum - 2 * A
    return sum - 2 * A;
  }
};