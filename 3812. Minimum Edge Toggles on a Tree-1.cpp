// mark
// 2179
// 撥洋蔥法 + 樹的拓撲排序

class Solution {
public:
  vector<int> minimumFlips(int n, vector<vector<int>> &edges, string start,
                           string target) {
    vector<vector<pair<int, int>>> adj(n);
    vector<int> indeg(n, 0);
    for (int i = 0; i < n - 1; ++i) {
      auto &e = edges[i];
      int u = e[0], v = e[1];
      adj[u].push_back({v, i});
      adj[v].push_back({u, i});
      indeg[u]++;
      indeg[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (indeg[i] == 1) {
        q.push(i);
      }
    }

    unordered_set<int> seen;
    set<int> selects;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      seen.insert(u);
      for (auto &[v, i] : adj[u]) {
        if (seen.count(v))
          continue;
        if (start[u] != target[u]) {
          start[u] = target[u];
          start[v] = (start[v] == '1') ? '0' : '1';
          selects.insert(i);
        }
        if (--indeg[v] == 1) {
          q.push(v);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      if (start[i] != target[i])
        return {-1};
    }

    vector<int> res(selects.begin(), selects.end());
    return res;
  }
};