// offinle queries
class Solution {
public:
  vector<int> minInterval(vector<vector<int>> &intervals,
                          vector<int> &queries) {
    int m = intervals.size(), n = queries.size();
    sort(intervals.begin(), intervals.end());
    using P = pair<int, int>;
    // min heap
    priority_queue<P, vector<P>, greater<P>> pq; // right, idx
    set<P> sset;                                 // sz, idx

    vector<P> qs; // q, idx
    for (int i = 0; i < n; ++i)
      qs.push_back({queries[i], i});
    sort(qs.begin(), qs.end());

    vector<int> res(n);

    int j = 0;
    for (int i = 0; i < n; ++i) {
      auto [q, qid] = qs[i];
      while (j < m && intervals[j][0] <= q) {
        pq.push({intervals[j][1], j});
        sset.insert({intervals[j][1] - intervals[j][0] + 1, j});
        j++;
      }
      while (!pq.empty() && pq.top().first < q) {
        auto [right, idx] = pq.top();
        pq.pop();
        sset.erase({right - intervals[idx][0] + 1, idx});
      }
      if (sset.empty())
        res[qid] = -1;
      else
        res[qid] = (*sset.begin()).first;
    }

    return res;
  }
};