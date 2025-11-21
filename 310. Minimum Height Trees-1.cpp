class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);

    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
      deg[u]++;
      deg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)
      if (deg[i] <= 1)
        q.push(i);

    int remain = n;
    while (remain > 2) {
      int size = q.size();
      remain -= size;
      while (size--) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
          if (--deg[v] == 1)
            q.push(v);
      }
    }

    vector<int> res;
    while (!q.empty()) {
      res.push_back(q.front());
      q.pop();
    }

    return res;
  }
};

class Solution {
public:
  int treeDiameter(int n, vector<vector<int>> &edges) {
    if (n == 1)
      return 0;

    vector<vector<int>> adj(n);
    for (auto &e : edges) {
      adj[e[0]].push_back(e[1]);
      adj[e[1]].push_back(e[0]);
    }

    auto bfs = [&](int start) -> pair<int, int> {
      vector<int> dist(n, -1);
      queue<int> q;
      q.push(start);
      dist[start] = 0;

      int far = start;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
          if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            q.push(v);
            if (dist[v] > dist[far]) {
              far = v;
            }
          }
        }
      }
      return {far, dist[far]};
    };

    // 第一次 BFS：從 0 找到一個直徑端點 u
    auto [u, _] = bfs(0);

    // 第二次 BFS：從 u 出發，找到另一端點 v，距離就是直徑長度
    auto [v, diameter] = bfs(u);

    return diameter; // 直徑 = 最長路徑的邊數
  }
};
