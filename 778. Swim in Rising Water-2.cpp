struct Node {
  int cost, i, j;
};

class Solution {
public:
  int swimInWater(vector<vector<int>> &grid) {
    int n = grid.size();

    vector<int> dirs{0, 1, 0, -1, 0};
    vector<vector<int>> dist(n, vector<int>(n, n * n));

    // min heap
    auto comp = [](auto &a, auto &b) { return a.cost > b.cost; };
    priority_queue<Node, vector<Node>, decltype(comp)> pq(comp);

    dist[0][0] = grid[0][0];
    pq.push({grid[0][0], 0, 0});
    while (!pq.empty()) {
      auto [cost, i, j] = pq.top();
      pq.pop();
      if (i == n - 1 && j == n - 1)
        return cost;
      if (cost > dist[i][j])
        continue;
      for (int k = 0; k < 4; ++k) {
        int ni = i + dirs[k], nj = j + dirs[k + 1];
        if (ni < 0 || ni >= n || nj < 0 || nj >= n)
          continue;
        int H = max(cost, grid[ni][nj]);
        if (H < dist[ni][nj]) {
          dist[ni][nj] = H;
          pq.push({H, ni, nj});
        }
      }
    }

    return -1;
  }
};
