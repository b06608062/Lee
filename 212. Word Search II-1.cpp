struct TrieNode {
  TrieNode *children[26];
  const string *word;
  TrieNode() {
    for (int i = 0; i < 26; ++i)
      children[i] = nullptr;
    word = nullptr;
  }
};

class Solution {
public:
  TrieNode *root;
  void addWord(const string &word) {
    TrieNode *ptr = root;
    for (auto ch : word) {
      if (!ptr->children[ch - 'a'])
        ptr->children[ch - 'a'] = new TrieNode();
      ptr = ptr->children[ch - 'a'];
    }
    ptr->word = &word;
  }
  vector<string> res;
  vector<int> dirs{0, 1, 0, -1, 0};
  int m, n;
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    m = board.size(), n = board[0].size();

    root = new TrieNode();
    for (auto &w : words)
      addWord(w);

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        dfs(board, i, j, root);

    return res;
  }

  void dfs(vector<vector<char>> &board, int i, int j, TrieNode *root) {
    if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] == '#')
      return;
    char ch = board[i][j];
    TrieNode *next = root->children[ch - 'a'];
    if (!next)
      return;
    if (next->word) {
      res.push_back(*next->word);
      next->word = nullptr;
    }
    board[i][j] = '#';
    for (int d = 0; d < 4; ++d)
      dfs(board, i + dirs[d], j + dirs[d + 1], next);
    board[i][j] = ch;
  }
};