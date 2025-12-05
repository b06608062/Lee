// mark
// 區間 DP
// 2130
class Solution {
public:
  int minScoreTriangulation(vector<int> &v) {
    int n = v.size();

    vector f(n, vector<int>(n, 0));

    for (int i = n - 3; i >= 0; i--)
      for (int j = i + 2; j < n; j++) {
        int best = INT_MAX / 2;
        for (int k = i + 1; k < j; k++)
          best = min(best, f[i][k] + f[k][j] + v[i] * v[j] * v[k]);
        f[i][j] = best;
      }

    return f[0][n - 1];
  }
};