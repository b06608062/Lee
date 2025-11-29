class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    int n = tasks.size();
    for (int i = 0; i < n; ++i)
      tasks[i].push_back(i);

    sort(tasks.begin(), tasks.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });

    using P = pair<int, int>; // pt, idx
    // min heap
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<int> res;
    int i = 0;
    long long time = 0;
    while (i < n || !pq.empty()) {
      if (pq.empty())
        time = max(time, 1ll * tasks[i][0]);
      while (i < n && time >= tasks[i][0]) {
        pq.push({tasks[i][1], tasks[i][2]});
        i++;
      }

      auto [pt, idx] = pq.top();
      pq.pop();
      time += pt;
      res.push_back(idx);
    }

    return res;
  }
};