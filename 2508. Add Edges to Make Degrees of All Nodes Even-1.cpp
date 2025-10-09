class Solution {
public:
  bool isPossible(int n, vector<vector<int>> &edges) {
    vector<int> deg(n + 1);
    vector<unordered_set<int>> adj(n + 1);

    for (auto &e : edges) {
      int u = e[0], v = e[1];
      deg[u]++;
      deg[v]++;
      adj[u].insert(v);
      adj[v].insert(u);
    }

    vector<int> odd;
    for (int i = 1; i <= n; ++i)
      if (deg[i] % 2 == 1)
        odd.push_back(i);

    if (odd.empty())
      return true;

    if (odd.size() == 2) {
      int u = odd[0], v = odd[1];
      if (!adj[u].count(v))
        return true;
      for (int i = 1; i <= n; ++i)
        if (i != u && i != v)
          if (!adj[u].count(i) && !adj[v].count(i))
            return true;
      return false;
    } else if (odd.size() == 4) {
      if (!adj[odd[0]].count(odd[1]) && !adj[odd[2]].count(odd[3]))
        return true;
      if (!adj[odd[0]].count(odd[2]) && !adj[odd[1]].count(odd[3]))
        return true;
      if (!adj[odd[0]].count(odd[3]) && !adj[odd[1]].count(odd[2]))
        return true;
      return false;
    }

    return false;
  }
};