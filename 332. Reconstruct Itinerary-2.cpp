class Solution {
public:
  unordered_map<string, priority_queue<string, vector<string>, greater<string>>>
      adj;
  vector<string> res;
  void dfs(string cur) {
    while (!adj[cur].empty()) {
      string nxt = adj[cur].top();
      adj[cur].pop();
      dfs(nxt);
    }
    res.push_back(cur);
  }
  vector<string> findItinerary(vector<vector<string>> &tickets) {
    for (auto &t : tickets)
      adj[t[0]].push(t[1]);
    dfs("JFK");
    reverse(res.begin(), res.end());
    return res;
  }
};