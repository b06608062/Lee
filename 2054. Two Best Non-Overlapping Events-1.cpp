// mark
// 1883
// 掃描線 + 優先佇列 + 維護左側最大值
class Solution {
public:
  int maxTwoEvents(vector<vector<int>> &events) {
    sort(events.begin(), events.end(),
         [](auto &a, auto &b) { return a[0] < b[0]; });

    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq; // et, v

    int res = 0, curMax = 0;
    for (auto &e : events) {
      int st = e[0], et = e[1], v = e[2];
      while (!pq.empty() && pq.top().first < st) {
        if (curMax < pq.top().second)
          curMax = pq.top().second;
        pq.pop();
      }
      res = max(res, v + curMax);
      pq.push({et, v});
    }

    return res;
  }
};