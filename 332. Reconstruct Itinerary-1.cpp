class Solution {
public:
  unordered_map<string, deque<string>> adj;
  vector<string> res;
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    for (auto &t : tickets)
      adj[t[0]].push_back(t[1]);

    for (auto &[_, dq] : adj)
      sort(dq.begin(), dq.end());

    string start = "JFK";
    dfs(start);

    reverse(res.begin(), res.end());
    return res;
  }

  void dfs(string &u) {
    auto &dq = adj[u];
    while (!dq.empty()) {
      string v = dq.front();
      dq.pop_front();
      dfs(v);
    }
    res.push_back(u);
  }
};