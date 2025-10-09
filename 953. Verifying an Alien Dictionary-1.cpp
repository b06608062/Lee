class Solution {
public:
  unordered_map<int, int> umap;
  bool isAlienSorted(vector<string> &words, string order) {
    for (int i = 0; i < 26; ++i)
      umap[order[i]] = i;

    for (int i = 0; i < words.size() - 1; ++i)
      if (!helper(words[i], words[i + 1]))
        return false;

    return true;
  }

  bool helper(string &s, string &t) {
    int l1 = s.size(), l2 = t.size();
    int l = min(l1, l2);
    for (int i = 0; i < l; ++i)
      if (s[i] != t[i])
        return umap[s[i]] < umap[t[i]];

    return l1 <= l2;
  }
};