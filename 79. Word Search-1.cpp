class Solution {
public:
  int m, n;
  vector<int> dirs{0, 1, 0, -1, 0};
  bool exist(vector<vector<char>> &board, string word) {
    m = board.size();
    n = board[0].size();
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (helper(board, word, i, j, 0))
          return true;

    return false;
  }

  bool helper(vector<vector<char>> &board, string &word, int i, int j,
              int idx) {
    if (idx == word.size())
      return true;
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#' ||
        board[i][j] != word[idx])
      return false;

    char ch = board[i][j];
    board[i][j] = '#';
    for (int k = 0; k < 4; ++k)
      if (helper(board, word, i + dirs[k], j + dirs[k + 1], idx + 1))
        return true;
    board[i][j] = ch;

    return false;
  }
};