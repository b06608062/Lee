class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    deque<pair<int, int>> dq;
    vector<vector<int>> dist(m + 1, vector<int>(n + 1, INT_MAX / 2));

    dq.push_back({0, 0});
    dist[0][0] = 0;
    while (!dq.empty()) {
      auto [i, j] = dq.front();
      dq.pop_front();
      if (i == m && j == n)
        return dist[i][j];
      if (i < m && j < n && word1[i] == word2[j]) {
        if (dist[i + 1][j + 1] > dist[i][j]) {
          dist[i + 1][j + 1] = dist[i][j];
          dq.push_front({i + 1, j + 1});
        }
      }
      // Replace w2[j] with w1[i]
      if (i < m && j < n && dist[i + 1][j + 1] > dist[i][j] + 1) {
        dist[i + 1][j + 1] = dist[i][j] + 1;
        dq.push_back({i + 1, j + 1});
      }
      // Insert w1[i] at position j in w2
      if (i < m && dist[i + 1][j] > dist[i][j] + 1) {
        dist[i + 1][j] = dist[i][j] + 1;
        dq.push_back({i + 1, j});
      }
      // Delete w2[j]
      if (j < n && dist[i][j + 1] > dist[i][j] + 1) {
        dist[i][j + 1] = dist[i][j] + 1;
        dq.push_back({i, j + 1});
      }
    }
    return dist[m][n];
  }
};