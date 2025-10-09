class Solution {
public:
  vector<string> board;
  vector<int> col, diag1, diag2;
  vector<vector<string>> res;
  vector<vector<string>> solveNQueens(int n) {
    board = vector<string>(n, string(n, '.'));
    col = vector<int>(n, 0);
    diag1 = vector<int>(2 * n - 1, 0);
    diag2 = vector<int>(2 * n - 1, 0);

    helper(n, 0);

    return res;
  }

  void helper(int n, int i) {
    if (i == n) {
      res.push_back(board);
      return;
    }

    for (int j = 0; j < n; ++j) {
      if (!isValid(n, i, j))
        continue;
      update(n, i, j, true);
      helper(n, i + 1);
      update(n, i, j, false);
    }
  }

  void update(int n, int i, int j, bool isPut) {
    col[j] = isPut;
    diag1[i + j] = isPut;
    diag2[i - j + n - 1] = isPut;
    board[i][j] = isPut ? 'Q' : '.';
  }

  bool isValid(int n, int i, int j) {
    return !col[j] && !diag1[i + j] && !diag2[i - j + n - 1];
  }
};