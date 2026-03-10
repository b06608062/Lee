class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int m = s1.size(), n = s2.size();
    if (m + n != s3.size())
      return false;
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(m + 1, vector<bool>(n + 1, false));
    q.push({0, 0});
    vis[0][0] = true;
    while (!q.empty()) {
      auto [i, j] = q.front();
      q.pop();
      if (i == m && j == n)
        return true;
      int k = i + j;
      if (i < m && s1[i] == s3[k] && !vis[i + 1][j]) {
        vis[i + 1][j] = true;
        q.push({i + 1, j});
      }
      if (j < n && s2[j] == s3[k] && !vis[i][j + 1]) {
        vis[i][j + 1] = true;
        q.push({i, j + 1});
      }
    }

    return false;
  }
};
