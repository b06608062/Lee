// mark
// 海平面上升 + 多源 BFS + Bucket (Dial's algorithm)
// O(mn + H) H = 最大高度
class Solution {
public:
  int trapRainWater(vector<vector<int>> &heightMap) {
    int m = heightMap.size(), n = heightMap[0].size();

    int maxH = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        maxH = max(maxH, heightMap[i][j]);

    // dist[i][j] = 這個 cell 被水包住時，所需的最小「邊界高度」
    const int INF = maxH + 1;
    vector<vector<int>> dist(m, vector<int>(n, INF));
    vector<vector<bool>> vis(m, vector<bool>(n, false));

    // bucket[h] 裡存所有 dist == h 的 cell
    vector<vector<pair<int, int>>> bucket(maxH + 1);

    // 多源初始化：所有邊界 cell 視為「堤防」，dist = 自己高度
    auto push_if_better = [&](int i, int j, int d) {
      dist[i][j] = d;
      bucket[d].push_back({i, j});
    };

    for (int i = 0; i < m; ++i) {
      push_if_better(i, 0, heightMap[i][0]);
      push_if_better(i, n - 1, heightMap[i][n - 1]);
    }
    for (int j = 0; j < n; ++j) {
      push_if_better(0, j, heightMap[0][j]);
      push_if_better(m - 1, j, heightMap[m - 1][j]);
    }

    vector<int> dirs{0, 1, 0, -1, 0};

    // Dial's algorithm：從低到高掃 bucket
    for (int curH = 0; curH <= maxH; ++curH) {
      auto &cells = bucket[curH];
      while (!cells.empty()) {
        auto [i, j] = cells.back();
        cells.pop_back();
        if (vis[i][j])
          continue;
        vis[i][j] = true;

        // 往四周鬆弛
        for (int k = 0; k < 4; ++k) {
          int ni = i + dirs[k];
          int nj = j + dirs[k + 1];
          if (ni < 0 || ni >= m || nj < 0 || nj >= n)
            continue;
          if (vis[ni][nj])
            continue;

          int newH = max(curH, heightMap[ni][nj]);
          if (newH < dist[ni][nj]) {
            dist[ni][nj] = newH;
            bucket[newH].push_back({ni, nj});
          }
        }
      }
    }

    // 計算總蓄水量：每格能裝 = dist - 自己的高度（如果 > 0）
    long long res = 0;
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (dist[i][j] > heightMap[i][j]) // 被較高的邊界包住
          res += dist[i][j] - heightMap[i][j];

    return res;
  }
};
