// dijkstra
struct Node {
  int cost, i, j;
};

class Solution {
public:
  int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();

    vector<int> dirs{0, 1, 0, -1, 0};
    vector<vector<int>> dist(m, vector<int>(n, 1e6));

    // min heap
    auto comp = [](auto &a, auto &b) { return a.cost > b.cost; };
    priority_queue<Node, vector<Node>, decltype(comp)> pq(comp);

    dist[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
      auto [cost, i, j] = pq.top();
      pq.pop();
      if (i == m - 1 && j == n - 1)
        return cost;
      if (cost > dist[i][j])
        continue;
      int fromH = heights[i][j];
      for (int k = 0; k < 4; ++k) {
        int ni = i + dirs[k], nj = j + dirs[k + 1];
        if (ni < 0 || ni >= m || nj < 0 || nj >= n)
          continue;
        int nCost = max(cost, abs(fromH - heights[ni][nj]));
        if (nCost < dist[ni][nj]) {
          dist[ni][nj] = nCost;
          pq.push({nCost, ni, nj});
        }
      }
    }

    return -1;
  }
};