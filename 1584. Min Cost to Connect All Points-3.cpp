class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();

    vector<int> best(n, INT_MAX / 2);

    using P = pair<int, int>; // w, u
    priority_queue<P, vector<P>, greater<P>> pq;

    best[0] = 0;
    pq.push({0, 0});
    int count = 0, res = 0;
    while (!pq.empty()) {
      auto [w, u] = pq.top();
      pq.pop();
      if (w > best[u])
        continue;
      res += w;
      best[u] = -1;
      if (++count == n)
        break;
      for (int v = 0; v < n; ++v) {
        if (best[v] == -1)
          continue;
        int c =
            abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
        if (c < best[v]) {
          best[v] = c;
          pq.push({c, v});
        }
      }
    }

    return res;
  }
};