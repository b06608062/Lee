class Trie {
public:
  struct TrieNode {
    bool isEnd;
    TrieNode *children[26];
  };

  TrieNode *root;

  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode *ptr = root;
    for (char ch : word) {
      if (!ptr->children[ch - 'a'])
        ptr->children[ch - 'a'] = new TrieNode();
      ptr = ptr->children[ch - 'a'];
    }
    ptr->isEnd = true;
  }

  bool search(string word) {
    TrieNode *ptr = root;
    for (char ch : word) {
      if (!ptr->children[ch - 'a'])
        return false;
      ptr = ptr->children[ch - 'a'];
    }

    return ptr->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode *ptr = root;
    for (char ch : prefix) {
      if (!ptr->children[ch - 'a'])
        return false;
      ptr = ptr->children[ch - 'a'];
    }

    return true;
    ;
  }
};
