class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();
    vector<int> f(n + 1, INT_MIN / 2);
    f[n] = 0;
    for (int i = n - 1; i >= 0; --i) {
      int sum = 0;
      for (int j = 0; j < 3 && i + j < n; ++j) {
        sum += stoneValue[i + j];
        f[i] = max(f[i], sum - f[i + j + 1]);
      }
    }
    return f[0] == 0 ? "Tie" : f[0] > 0 ? "Alice" : "Bob";
  }
};

class Solution {
public:
  string stoneGameIII(vector<int> &stoneValue) {
    int n = stoneValue.size();
    vector<int> f(4);
    f[n % 4] = 0;
    for (int i = n - 1; i >= 0; --i) {
      int sum = 0;
      f[i % 4] = INT_MIN / 2;
      for (int j = 0; j < 3 && i + j < n; ++j) {
        sum += stoneValue[i + j];
        f[i % 4] = max(f[i % 4], sum - f[(i + j + 1) % 4]);
      }
    }
    return f[0] == 0 ? "Tie" : f[0] > 0 ? "Alice" : "Bob";
  }
};