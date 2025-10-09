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