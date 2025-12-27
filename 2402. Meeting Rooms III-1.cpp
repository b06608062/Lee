// mark
// 2093
// 經典會議室分配問題 + 排序 + 維護兩個優先佇列
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

    long long cur = 0;
    for (int i = 0; i < meetings.size(); ++i) {
      long long st = meetings[i][0], et = meetings[i][1];
      cur = max(cur, st);
      if (free.empty() && cur < busy.top().first)
        cur = busy.top().first;
      while (!busy.empty() && cur >= busy.top().first) {
        free.push(busy.top().second);
        busy.pop();
      }
      int id = free.top();
      free.pop();
      cnt[id]++;
      busy.push({cur + et - st, id});
    }

    int maxCnt = 0, res = -1;
    for (int i = 0; i < n; ++i)
      if (cnt[i] > maxCnt) {
        maxCnt = cnt[i];
        res = i;
      }

    return res;
  }
};