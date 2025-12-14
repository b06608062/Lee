// mark
// 2238
// 樹形 DP
class Solution {
public:
  unordered_map<int, int> cntFreq; // node -> freq
  vector<vector<int>> adj;
  int minimumTotalPrice(int n, vector<vector<int>> &edges, vector<int> &price,
                        vector<vector<int>> &trips) {
    adj.resize(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (auto &trip : trips) {
      int s = trip[0], t = trip[1];
      vector<int> vis(n, 0);
      dfs1(vis, s, t);
    }

    vector<int> vis(n, 0);
    auto res = dfs2(price, vis, 0);

    return min(res.first, res.second);
  }

  // 統計每個點訪問頻率
  bool dfs1(vector<int> &vis, int u, int t) {
    vis[u] = true;
    if (u == t) {
      cntFreq[u]++;
      return true;
    }
    for (auto v : adj[u]) {
      if (!vis[v] && dfs1(vis, v, t)) {
        cntFreq[u]++;
        return true;
      }
    }
    return false;
  }

  // 樹形 DP，跑一次 DFS 從鄰居獲取成本資訊
  // 每個節點 u 都可以選擇 price 減半或 price 不減半
  // u_nh : 不減半
  // u_h : 減半
  // 如果 u 選擇減半，那只能取 v 不減半的路
  // 如果 u 選擇不減半，那可以取 min(v 不減半, v 減半)
  pair<int, int> dfs2(vector<int> &price, vector<int> &vis, int u) {
    vis[u] = 1;
    int u_nh = cntFreq[u] * price[u];
    int u_h = u_nh / 2;
    for (auto v : adj[u]) {
      if (vis[v])
        continue;
      auto [v_nh, v_h] = dfs2(price, vis, v);
      u_nh += min(v_nh, v_h);
      u_h += v_nh;
    }

    return {u_nh, u_h};
  }
};