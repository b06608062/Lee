class Solution {
public:
  int mostBooked(int n, vector<vector<int>> &meetings) {
    sort(meetings.begin(), meetings.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });

    // min heap
    using P = pair<long long, int>; // time, id
    priority_queue<P, vector<P>, greater<P>> busy;
    priority_queue<int, vector<int>, greater<int>> free;
    for (int i = 0; i < n; ++i)
      free.push(i);

    vector<int> cnt(n, 0);

    for (auto &m : meetings) {
      long long st = m[0], et = m[1];
      while (!busy.empty() && busy.top().first <= st) {
        free.push(busy.top().second);
        busy.pop();
      }
      if (!free.empty()) {
        int id = free.top();
        free.pop();
        busy.push({et, id});
        cnt[id]++;
      } else {
        auto [avt, id] = busy.top();
        busy.pop();
        busy.push({avt + et - st, id});
        cnt[id]++;
      }
    }

    int maxCnt = -1, res = -1;
    for (int i = 0; i < n; ++i)
      if (cnt[i] > maxCnt) {
        maxCnt = cnt[i];
        res = i;
      }

    return res;
  }
};