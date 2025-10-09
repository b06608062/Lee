class WordDictionary {
public:
  struct TrieNode {
    bool isEnd;
    TrieNode *children[26];
  };

  TrieNode *root;

  WordDictionary() { root = new TrieNode(); }

  void addWord(string word) {
    TrieNode *ptr = root;
    for (char ch : word) {
      if (!ptr->children[ch - 'a'])
        ptr->children[ch - 'a'] = new TrieNode();
      ptr = ptr->children[ch - 'a'];
    }
    ptr->isEnd = true;
  }

  bool search(string word) { return helper(word, root, 0); }

  bool helper(string &word, TrieNode *root, int idx) {
    if (idx == word.size())
      return root->isEnd;

    TrieNode *ptr = root;
    char ch = word[idx];
    if (ch == '.') {
      for (int i = 0; i < 26; ++i)
        if (ptr->children[i] && helper(word, ptr->children[i], idx + 1))
          return true;
    } else
      return ptr->children[ch - 'a'] &&
             helper(word, ptr->children[ch - 'a'], idx + 1);

    return false;
  }
};