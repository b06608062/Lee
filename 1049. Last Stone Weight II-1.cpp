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

class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    vector<int> f(sum + 1, 0);
    f[0] = 1;
    for (auto x : stones) {
      for (int i = sum; i >= x; --i)
        f[i] |= f[i - x];
    }
    for (int i = sum / 2; i >= 0; --i)
      if (f[i])
        return sum - 2 * i;
    return -1;
  }
};

// 0/1 knapsack problem
// dp[t] 代表的是「當背包容量為 t 時，能裝入的最大重量」。
class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;
    vector<int> dp(target + 1, 0);

    for (int stone : stones)
      for (int t = target; t >= stone; --t)
        dp[t] = max(dp[t], dp[t - stone] + stone);

    return sum - 2 * dp[target];
  }
};