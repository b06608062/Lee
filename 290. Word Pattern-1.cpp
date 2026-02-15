// mark
// 雙向映射
// stringstream 操作

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    int n = s.size();

    unordered_map<char, string> umap;
    unordered_set<string> uset;

    int idx = 0, i = 0;
    while (i < n) {
      int j = i;
      while (j < n && s[j] != ' ') {
        j++;
      }
      string str = s.substr(i, j - i);
      if (idx == pattern.size()) {
        return false;
      }
      char ch = pattern[idx++];
      if (umap.count(ch)) {
        if (umap[ch] != str) {
          return false;
        }
      } else {
        if (uset.count(str)) {
          return false;
        }
        umap[ch] = str;
        uset.insert(str);
      }
      i = j + 1;
    }

    return idx == pattern.size() ? true : false;
  }
};

class Solution {
public:
  bool wordPattern(string pattern, string s) {
    unordered_map<char, string> p2s;
    unordered_map<string, char> s2p;

    vector<string> words;
    stringstream ss(s);
    string word;
    while (ss >> word)
      words.push_back(word);

    if (words.size() != pattern.size())
      return false;

    for (int i = 0; i < pattern.size(); ++i) {
      char c = pattern[i];
      string w = words[i];

      if (p2s.count(c) && p2s[c] != w)
        return false;
      if (s2p.count(w) && s2p[w] != c)
        return false;

      p2s[c] = w;
      s2p[w] = c;
    }
    return true;
  }
};