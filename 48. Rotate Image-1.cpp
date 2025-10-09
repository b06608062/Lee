class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix.size();

    for (int i = 0; i < n / 2; ++i) {
      for (int k = i; k <= n - 1 - i - 1; ++k) {
        int temp = matrix[i][k];
        matrix[i][k] = matrix[n - 1 - k][i];
        matrix[n - 1 - k][i] = matrix[n - 1 - i][n - 1 - k];
        matrix[n - 1 - i][n - 1 - k] = matrix[k][n - 1 - i];
        matrix[k][n - 1 - i] = temp;
      }
    }
  }
};