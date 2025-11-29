class Solution {
public:
  vector<int> col, diag1, diag2;
  int res = 0;
  int totalNQueens(int n) {
    col = vector<int>(n, 0);
    diag1 = vector<int>(2 * n - 1, 0);
    diag2 = vector<int>(2 * n - 1, 0);

    helper(n, 0);

    return res;
  }

  void helper(int n, int i) {
    if (i == n) {
      res++;
      return;
    }

    for (int j = 0; j < n; ++j) {
      if (col[j] || diag1[i + j] || diag2[i - j + n - 1])
        continue;
      col[j] = diag1[i + j] = diag2[i - j + n - 1] = true;
      helper(n, i + 1);
      col[j] = diag1[i + j] = diag2[i - j + n - 1] = false;
    }
  }
};