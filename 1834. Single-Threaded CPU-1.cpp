class Solution {
public:
  vector<int> getOrder(vector<vector<int>> &tasks) {
    for (int i = 0; i < tasks.size(); ++i)
      tasks[i].push_back(i);

    sort(tasks.begin(), tasks.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });

    using P = pair<int, int>; // p, idx
    // min heap
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<int> res;
    int curTime = 0;
    for (auto &t : tasks) {
      while (!pq.empty() && curTime < t[0]) {
        auto p = pq.top();
        pq.pop();
        res.push_back(p.second);
        curTime += p.first;
      }

      curTime = max(curTime, t[0]);

      pq.push({t[1], t[2]});
    }

    while (!pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
    }

    return res;
  }
};