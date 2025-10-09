struct Node {
  int h, i, j;
};

class Solution {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();

    vector<int> dirs{0, 1, 0, -1, 0};
    vector<vector<int>> vis(m, vector<int>(n, 0));

    // min heap
    auto comp = [](auto &a, auto &b) { return a.h > b.h; };
    priority_queue<Node, vector<Node>, decltype(comp)> pq(comp);
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
          vis[i][j] = 1;
          pq.push({heightMap[i][j], i, j});
        }

    int curH = 0, res = 0;
    while (!pq.empty()) {
      auto [h, i, j] = pq.top();
      pq.pop();
      curH = max(curH, h);
      res += curH - h;
      for (int k = 0; k < 4; ++k) {
        int ni = i + dirs[k], nj = j + dirs[k + 1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n || vis[ni][nj])
          continue;
        vis[ni][nj] = 1;
        pq.push({heightMap[ni][nj], ni, nj});
      }
    }

    return res;
  }
};