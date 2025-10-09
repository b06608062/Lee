class Solution {
public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();

    vector<int> best(n, INT_MAX / 2);
    vector<int> in(n, 0);

    using P = pair<int, int>;
    // min heap
    priority_queue<P, vector<P>, greater<P>> pq; // w, u

    best[0] = 0;
    pq.push({0, 0});
    int count = 0, res = 0;
    while (!pq.empty()) {
      auto [w, u] = pq.top();
      pq.pop();
      if (in[u])
        continue;
      in[u] = 1;
      res += w;
      if (++count == n)
        break;
      for (int v = 0; v < n; ++v) {
        if (!in[v]) {
          int c = abs(points[u][0] - points[v][0]) +
                  abs(points[u][1] - points[v][1]);
          if (c < best[v]) {
            best[v] = c;
            pq.push({c, v});
          }
        }
      }
    }

    return res;
  }
};