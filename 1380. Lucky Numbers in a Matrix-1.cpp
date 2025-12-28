class Solution {
public:
  vector<int> luckyNumbers(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();

    vector<int> row(m, INT_MAX / 2), col(n, INT_MIN / 2);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int x = matrix[i][j];
        row[i] = min(row[i], x);
        col[j] = max(col[j], x);
      }
    }

    vector<int> res;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (row[i] == col[j])
          res.push_back(matrix[i][j]);

    return res;
  }
};