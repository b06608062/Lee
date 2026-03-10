class Solution {
public:
  vector<vector<int>> memo;
  int m, n;
  int minDistance(string word1, string word2) {
    m = word1.size(), n = word2.size();
    memo.assign(m + 1, vector<int>(n + 1, -1));
    return dfs(word1, word2, m, n);
  }

  int dfs(string &w1, string &w2, int i, int j) {
    if (i == 0 || j == 0)
      return i == 0 ? j : i;
    int &res = memo[i][j];
    if (res != -1)
      return res;
    if (w1[i - 1] == w2[j - 1])
      return res = dfs(w1, w2, i - 1, j - 1);
    return res = min({dfs(w1, w2, i - 1, j - 1), dfs(w1, w2, i, j - 1),
                      dfs(w1, w2, i - 1, j)}) +
                 1;
  }
};
