class Solution {
public:
  int change(int amount, vector<int> &coins) {
    vector<unsigned int> f(amount + 1, 0);
    f[0] = 1;
    for (auto c : coins) {
      for (int i = c; i <= amount; ++i)
        f[i] += f[i - c];
    }
    return f[amount];
  }
};

class Solution {
public:
  int change(int amount, vector<int> &coins) {
    int n = coins.size();
    vector<vector<unsigned int>> f(n + 1, vector<unsigned int>(amount + 1, 0));

    for (int i = 0; i <= n; ++i)
      f[i][0] = 1;

    for (int i = 1; i <= n; ++i) {
      int x = coins[i - 1];
      for (int j = 1; j <= amount; ++j) {
        f[i][j] = f[i - 1][j];
        if (j >= x) {
          f[i][j] += f[i][j - x];
        }
      }
    }

    return f[n][amount];
  }
};