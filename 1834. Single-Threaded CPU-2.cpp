class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    int n = tasks.size();
    for (int i = 0; i < n; ++i)
      tasks[i].push_back(i);
    sort(tasks.begin(), tasks.end());

    using P = pair<int, int>; // p_t, idx
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<int> res;
    long long cur = 0;
    int i = 0;
    while (i < n || !pq.empty()) {
      if (pq.empty())
        cur = max(cur, 1ll * tasks[i][0]);
      while (i < n && tasks[i][0] <= cur) {
        pq.push({tasks[i][1], tasks[i][2]});
        ++i;
      }
      auto [p_t, idx] = pq.top();
      pq.pop();
      cur += p_t;
      res.push_back(idx);
    }
    return res;
  }
};