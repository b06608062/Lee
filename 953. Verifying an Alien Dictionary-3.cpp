struct TrieNode {
  vector<int> ids;
  TrieNode *children[26];
  TrieNode() {
    for (int i = 0; i < 26; ++i)
      children[i] = nullptr;
  }
};

class Solution {
public:
  TrieNode *root;
  vector<int> arr;
  bool isAlienSorted(vector<string> &words, string order) {
    int n = words.size();
    root = new TrieNode();
    for (int i = 0; i < n; ++i)
      insert(words[i], i);

    dfs(root, order);

    for (int i = 1; i < n; ++i)
      if (arr[i - 1] > arr[i])
        return false;

    return true;
  }

  void insert(string &w, int idx) {
    TrieNode *ptr = root;
    for (char &c : w) {
      if (!ptr->children[c - 'a'])
        ptr->children[c - 'a'] = new TrieNode();
      ptr = ptr->children[c - 'a'];
    }
    ptr->ids.push_back(idx);
  }

  void dfs(TrieNode *ptr, string &order) {
    for (auto idx : ptr->ids)
      arr.push_back(idx);
    for (char &c : order)
      if (ptr->children[c - 'a'])
        dfs(ptr->children[c - 'a'], order);
  }
};