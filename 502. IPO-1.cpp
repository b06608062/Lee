class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    int n = profits.size();
    // min heap
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> minPq; // c, p
    for (int i = 0; i < n; ++i)
      minPq.push({capital[i], profits[i]});

    // max heap
    priority_queue<int> maxPq;

    while (!minPq.empty() && w >= minPq.top().first) {
      maxPq.push(minPq.top().second);
      minPq.pop();
    }

    int cur = w;
    while (k-- && !maxPq.empty()) {
      cur += maxPq.top();
      maxPq.pop();
      while (!minPq.empty() && cur >= minPq.top().first) {
        maxPq.push(minPq.top().second);
        minPq.pop();
      }
    }

    return cur;
  }
};