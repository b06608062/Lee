class Solution {
public:
  vector<string> res;
  string cur = "";
  string getHappyString(int n, int k) {
    dfs(n, 0, -1);
    sort(res.begin(), res.end());
    return k <= res.size() ? res[k - 1] : "";
  }

  void dfs(int n, int i, int j) {
    if (i == n) {
      res.push_back(cur);
      return;
    }
    for (int k = 0; k < 3; ++k) {
      if (k == j)
        continue;
      cur += 'a' + k;
      dfs(n, i + 1, k);
      cur.pop_back();
    }
  }
};