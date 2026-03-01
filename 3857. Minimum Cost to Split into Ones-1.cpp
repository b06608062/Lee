class Solution {
public:
  int minCost(int n) {
    vector<int> f(n + 1, INT_MAX / 2);
    f[1] = 0;
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= i / 2; ++j) {
        int k = i - j;
        f[i] = min(f[i], f[j] + f[k] + j * k);
      }
    }
    return f[n];
  }
};