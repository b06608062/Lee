class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();
    vector<int> f(n + 1, INT_MIN / 2), suff(n + 1, 0);
    f[n] = 0;
    for (int i = n - 1; i >= 0; --i)
      suff[i] = suff[i + 1] + stoneValue[i];

    for (int i = n - 1; i >= 0; --i) {
      int sum = 0;
      for (int j = 0; j < 3 && i + j < n; ++j) {
        sum += stoneValue[i + j];
        f[i] = max(f[i], sum + (suff[i + j + 1] - f[i + j + 1]));
      }
    }

    int diff = f[0] - (suff[0] - f[0]);
    return diff == 0 ? "Tie" : diff > 0 ? "Alice" : "Bob";
  }
};