class Solution {
public:
  int findMaximizedCapital(int k, int w, vector<int> &profits,
                           vector<int> &capital) {
    int n = capital.size();
    priority_queue<int> av_pq;
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> cap_pq;
    for (int i = 0; i < n; ++i)
      cap_pq.push({capital[i], profits[i]});
    int cur = w;
    while (k--) {
      while (!cap_pq.empty() && cap_pq.top().first <= cur) {
        av_pq.push(cap_pq.top().second);
        cap_pq.pop();
      }
      if (av_pq.empty())
        break;
      cur += av_pq.top();
      av_pq.pop();
    }
    return cur;
  }
};