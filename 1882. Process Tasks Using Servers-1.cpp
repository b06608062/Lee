class Solution {
public:
  vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
    int n = servers.size(), m = tasks.size();

    vector<int> res(m, -1);

    using P = pair<long long, int>;
    priority_queue<P, vector<P>, greater<P>> free, busy; // (w, sid) (t, sid)
    for (int i = 0; i < n; ++i)
      free.push({servers[i], i});

    long long cur = 0;
    for (int j = 0; j < m; ++j) {
      cur = max(cur, (long long)j);
      if (free.empty() && busy.top().first > cur)
        cur = busy.top().first;
      while (!busy.empty() && busy.top().first <= cur) {
        int sid = busy.top().second;
        busy.pop();
        free.push({servers[sid], sid});
      }
      int sid = free.top().second;
      free.pop();
      busy.push({cur + tasks[j], sid});
      res[j] = sid;
    }

    return res;
  }
};