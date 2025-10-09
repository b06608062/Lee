class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    priority_queue<int> pq;

    for (auto x : stones)
      pq.push(x);

    while (pq.size() >= 2) {
      int y = pq.top();
      pq.pop();
      int x = pq.top();
      pq.pop();
      if (y != x)
        pq.push(y - x);
    }

    return pq.empty() ? 0 : pq.top();
  }
};