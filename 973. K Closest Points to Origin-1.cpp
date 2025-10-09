class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
    auto comp = [](auto &a, auto &b) {
      return (a.first * a.first + a.second * a.second) <
             (b.first * b.first + b.second * b.second);
    };
    using P = pair<int, int>;
    priority_queue<P, vector<P>, decltype(comp)> pq(comp);

    for (auto p : points) {
      pq.push({p[0], p[1]});
      if (pq.size() > k)
        pq.pop();
    }

    vector<vector<int>> res;
    while (!pq.empty()) {
      auto p = pq.top();
      pq.pop();
      res.push_back({p.first, p.second});
    }

    return res;
  }
};