class Solution {
public:
  struct TrieNode {
    bool isEnd;
    TrieNode *children[26];
  };
  TrieNode *root;

  void insert(string &word) {
    TrieNode *ptr = root;
    for (char ch : word) {
      if (!ptr->children[ch - 'a'])
        ptr->children[ch - 'a'] = new TrieNode();
      ptr = ptr->children[ch - 'a'];
    }
    ptr->isEnd = true;
  }

  int minExtraChar(string s, vector<string> &dictionary) {
    int n = s.size();

    root = new TrieNode();
    for (auto &word : dictionary)
      insert(word);

    vector<int> dp(n + 1, 0);

    for (int i = n - 1; i >= 0; --i) {
      int best = 1 + dp[i + 1];
      TrieNode *ptr = root;
      for (int j = i; j < n; ++j) {
        char ch = s[j];
        if (ptr->children[ch - 'a']) {
          ptr = ptr->children[ch - 'a'];
          if (ptr->isEnd)
            best = min(best, dp[j + 1]);
          if (best == 0)
            break;
        } else
          break;
      }
      dp[i] = best;
    }

    return dp[0];
  }
};