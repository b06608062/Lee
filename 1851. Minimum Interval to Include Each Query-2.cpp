// offinle queries
// lazy pop
class Solution {
public:
  vector<int> minInterval(vector<vector<int>> &intervals,
                          vector<int> &queries) {
    int m = intervals.size(), n = queries.size();
    sort(intervals.begin(), intervals.end());
    using P = pair<int, int>;
    // min heap
    priority_queue<P, vector<P>, greater<P>> pq; // sz, right

    vector<P> qs; // q, idx
    for (int i = 0; i < n; ++i)
      qs.push_back({queries[i], i});
    sort(qs.begin(), qs.end());

    vector<int> res(n);

    int j = 0;
    for (int i = 0; i < n; ++i) {
      auto [q, qid] = qs[i];
      while (j < m && intervals[j][0] <= q) {
        pq.push({intervals[j][1] - intervals[j][0] + 1, intervals[j][1]});
        j++;
      }
      while (!pq.empty() && pq.top().second < q)
        pq.pop();
      if (pq.empty())
        res[qid] = -1;
      else
        res[qid] = pq.top().first;
    }

    return res;
  }
};