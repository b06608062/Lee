class Solution {
public:
  int minReorder(int n, vector<vector<int>> &connections) {
    vector<vector<pair<int, int>>> adj(n);
    vector<bool> vis(n, false);
    for (auto &e : connections) {
      int u = e[0], v = e[1];
      adj[u].push_back({v, 1});
      adj[v].push_back({u, 0});
    }

    stack<int> st;

    st.push(0);
    vis[0] = true;
    int res = 0;
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      for (auto [v, cost] : adj[u])
        if (!vis[v]) {
          vis[v] = true;
          res += cost;
          st.push(v);
        }
    }

    return res;
  }
};