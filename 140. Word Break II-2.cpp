class Solution {
public:
  unordered_set<string> dict;
  unordered_map<int, vector<string>> memo;
  int n;
  vector<string> wordBreak(string s, vector<string> &wordDict) {
    n = s.size();

    for (auto &w : wordDict)
      dict.insert(w);

    return dfs(s, 0);
  }

  vector<string> dfs(string &s, int i) {
    if (memo.count(i))
      return memo[i];

    vector<string> res;
    if (i == n) {
      res.push_back("");
      return memo[i] = res;
    }

    for (int j = i + 1; j <= n; ++j) {
      string word = s.substr(i, j - i);
      if (!dict.count(word))
        continue;
      auto tails = dfs(s, j);
      for (auto &tail : tails) {
        if (tail.empty())
          res.push_back(word);
        else
          res.push_back(word + " " + tail);
      }
    }

    return memo[i] = res;
  }
};
