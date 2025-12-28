// mark
// 2139
// 貢獻法 從每個邊被經過幾次去計算 + 乘法原理
class Solution {
public:
  vector<vector<int>> adj;
  unordered_map<int, int> total; // g -> cnt
  long long res = 0;
  long long interactionCosts(int n, vector<vector<int>> &edges,
                             vector<int> &group) {
    adj.resize(n);
    for (auto &e : edges) {
      int u = e[0], v = e[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    for (auto g : group)
      total[g]++;

    dfs(group, 0, -1);

    return res;
  }

  unordered_map<int, int> dfs(vector<int> &group, int u, int p) {
    unordered_map<int, int> cnt_u;
    cnt_u[group[u]]++;
    for (auto v : adj[u]) {
      if (v == p)
        continue;
      auto cnt_v = dfs(group, v, u);
      for (auto [g, cnt] : cnt_v) {
        res += 1ll * cnt * (total[g] - cnt);
        cnt_u[g] += cnt;
      }
    }
    return cnt_u;
  }
};