class Solution {
public:
  long long maxMatrixSum(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    int cnt = 0, mn = INT_MAX;
    long long sum = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        int x = matrix[i][j];
        if (x <= 0)
          cnt++;
        mn = min(mn, abs(x));
        sum += abs(x);
      }
    if (cnt % 2 == 0)
      return sum;
    return sum - 2 * mn;
  }
};