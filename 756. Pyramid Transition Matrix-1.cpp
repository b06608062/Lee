// mark
// 1990
// Backtracking with Memoization
class Solution {
public:
  unordered_map<string, vector<char>> umap;
  unordered_map<string, bool> memo;
  bool pyramidTransition(string bottom, vector<string> &allowed) {
    for (auto &a : allowed)
      umap[a.substr(0, 2)].push_back(a[2]);

    return dfs(bottom, "");
  }

  bool dfs(string cur, string nxt) {
    if (cur.size() == 1)
      return true;

    string key = cur + "#" + nxt;
    if (memo.count(key))
      return memo[key];

    memo[key] = false;

    if (cur.size() - 1 == nxt.size()) {
      memo[key] = dfs(nxt, "");
      return memo[key];
    }

    int pos = nxt.size();
    if (!umap.count(cur.substr(pos, 2)))
      return false;

    for (auto ch : umap[cur.substr(pos, 2)])
      if (dfs(cur, nxt + ch)) {
        memo[key] = true;
        return true;
      }

    return false;
  }
};