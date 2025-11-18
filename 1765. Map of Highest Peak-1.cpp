class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>> &isWater) {
    int m = isWater.size(), n = isWater[0].size();

    vector<int> dirs{0, 1, 0, -1, 0};

    using P = pair<int, int>;
    queue<P> q;

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (isWater[i][j] == 1) {
          isWater[i][j] = 0;
          q.push({i, j});
        } else
          isWater[i][j] = -1;

    while (!q.empty()) {
      auto [ui, uj] = q.front();
      q.pop();
      int cur = isWater[ui][uj];
      for (int d = 0; d < 4; ++d) {
        int vi = ui + dirs[d], vj = uj + dirs[d + 1];
        if (vi >= 0 && vi < m && vj >= 0 && vj < n && isWater[vi][vj] == -1) {
          isWater[vi][vj] = cur + 1;
          q.push({vi, vj});
        }
      }
    }

    return isWater;
  }
};