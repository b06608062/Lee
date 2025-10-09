class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    sort(trips.begin(), trips.end(),
         [](auto &a, auto &b) { return a[1] < b[1]; });

    // min heap
    using P = pair<int, int>; // t, p
    priority_queue<P, vector<P>, greater<P>> pq;

    int carry = 0;
    for (auto &t : trips) { // p, f, t
      int time = t[1];
      while (!pq.empty() && time >= pq.top().first) {
        carry -= pq.top().second;
        pq.pop();
      }

      carry += t[0];
      if (carry > capacity)
        return false;
      pq.push({t[2], t[0]});
    }

    return true;
  }
};