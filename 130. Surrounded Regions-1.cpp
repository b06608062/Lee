class Solution {
public:
  int m, n;
  vector<int> dirs{0, 1, 0, -1, 0};
  void solve(vector<vector<char>> &board) {
    m = board.size();
    n = board[0].size();

    for (int i = 0; i < m; ++i) {
      dfs(board, i, 0);
      dfs(board, i, n - 1);
    }

    for (int j = 0; j < n; ++j) {
      dfs(board, 0, j);
      dfs(board, m - 1, j);
    }

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (board[i][j] == '#')
          board[i][j] = 'O';
        else
          board[i][j] = 'X';
  }

  void dfs(vector<vector<char>> &board, int i, int j) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
      return;

    board[i][j] = '#';
    for (int k = 0; k < 4; ++k)
      dfs(board, i + dirs[k], j + dirs[k + 1]);
  }
};