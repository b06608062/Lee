// mark
// 2118
// Trie 空間壓縮
struct TrieNode {
  pair<int, int> smallest; // len, idx
  int children[26];
  TrieNode() {
    memset(children, -1, sizeof(children));
    smallest = {INT_MAX, INT_MAX};
  }
};

class Solution {
public:
  vector<TrieNode> trieNodes;
  int root;
  vector<int> stringIndices(vector<string> &wordsContainer,
                            vector<string> &wordsQuery) {
    trieNodes.push_back(TrieNode()); // root
    root = 0;

    for (int i = 0; i < wordsContainer.size(); ++i) {
      auto &w = wordsContainer[i];
      int l = w.size();
      int ptr = root;
      trieNodes[ptr].smallest = min(trieNodes[ptr].smallest, {l, i});
      for (int j = l - 1; j >= 0; --j) {
        int c = w[j] - 'a';
        int nxt = trieNodes[ptr].children[c];
        if (nxt == -1) {
          nxt = trieNodes.size();
          trieNodes.push_back(TrieNode());
          trieNodes[ptr].children[c] = nxt;
        }
        ptr = nxt;
        trieNodes[ptr].smallest = min(trieNodes[ptr].smallest, {l, i});
      }
    }

    vector<int> res;
    for (const string &w : wordsQuery) {
      int l = w.size();
      int ptr = root;
      for (int j = l - 1; j >= 0; --j) {
        int c = w[j] - 'a';
        int nxt = trieNodes[ptr].children[c];
        if (nxt == -1)
          break;
        ptr = nxt;
      }
      res.push_back(trieNodes[ptr].smallest.second);
    }

    return res;
  }
};

struct TrieNode {
  pair<int, int> smallest; // len, idx
  TrieNode *children[26];
  TrieNode() {
    for (int i = 0; i < 26; ++i)
      children[i] = nullptr;
    smallest = {INT_MAX, INT_MAX};
  }
};

void remove(TrieNode *node) {
  for (int i = 0; i < 26; ++i)
    if (node->children[i])
      remove(node->children[i]);
  delete node;
}

class Solution {
public:
  TrieNode *root;
  vector<int> stringIndices(vector<string> &wordsContainer,
                            vector<string> &wordsQuery) {
    root = new TrieNode();
    for (int i = 0; i < wordsContainer.size(); ++i) {
      string &w = wordsContainer[i];
      reverse(w.begin(), w.end());
      int l = w.size();
      TrieNode *ptr = root;
      ptr->smallest = min(ptr->smallest, {l, i});
      for (auto ch : w) {
        if (!ptr->children[ch - 'a'])
          ptr->children[ch - 'a'] = new TrieNode();
        ptr = ptr->children[ch - 'a'];
        ptr->smallest = min(ptr->smallest, {l, i});
      }
    }

    vector<int> res;
    for (auto &w : wordsQuery) {
      reverse(w.begin(), w.end());
      TrieNode *ptr = root;
      for (auto ch : w) {
        if (ptr->children[ch - 'a'])
          ptr = ptr->children[ch - 'a'];
        else
          break;
      }
      res.push_back(ptr->smallest.second);
    }

    remove(root);

    return res;
  }
};

struct TrieNode {
  pair<int, int> smallest; // len, idx
  unordered_map<char, TrieNode> children;
  TrieNode() { smallest = {INT_MAX, INT_MAX}; }
};

class Solution {
public:
  TrieNode *root;
  vector<int> stringIndices(vector<string> &wordsContainer,
                            vector<string> &wordsQuery) {
    root = new TrieNode();
    for (int i = 0; i < wordsContainer.size(); ++i) {
      string &w = wordsContainer[i];
      reverse(w.begin(), w.end());
      int l = w.size();
      TrieNode *ptr = root;
      ptr->smallest = min(ptr->smallest, {l, i});
      for (char ch : w) {
        if (!ptr->children.count(ch))
          ptr->children[ch] = TrieNode();
        ptr = &ptr->children[ch];
        ptr->smallest = min(ptr->smallest, {l, i});
      }
    }

    vector<int> res;
    for (auto &w : wordsQuery) {
      reverse(w.begin(), w.end());
      TrieNode *ptr = root;
      for (char ch : w) {
        if (ptr->children.count(ch))
          ptr = &ptr->children[ch];
        else
          break;
      }
      res.push_back(ptr->smallest.second);
    }

    return res;
  }
};
