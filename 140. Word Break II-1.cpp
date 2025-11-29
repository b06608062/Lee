class Solution {
public:
  unordered_set<string> dict;
  vector<string> res;
  vector<string> subset;
  int n;
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    n = s.size();

    for (auto &w : wordDict)
      dict.insert(w);

    dfs(s, 0);

    return res;
  }

  void dfs(string &s, int i) {
    if (i == n) {
      string sentence = "";
      for (auto &t : subset)
        sentence += t + " ";
      sentence.pop_back();
      res.push_back(sentence);
      return;
    }

    for (int j = i; j < n; ++j) {
      string t = s.substr(i, j - i + 1);
      if (dict.count(t)) {
        subset.push_back(t);
        dfs(s, j + 1);
        subset.pop_back();
      }
    }
  }
};