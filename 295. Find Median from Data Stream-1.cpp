class MedianFinder {
public:
  priority_queue<int, vector<int>, greater<int>> mn_pq;
  priority_queue<int, vector<int>, less<int>> mx_pq;
  MedianFinder() {}

  void addNum(int num) {
    if (mx_pq.empty() || num <= mx_pq.top())
      mx_pq.push(num);
    else
      mn_pq.push(num);

    if (mn_pq.size() > mx_pq.size()) {
      mx_pq.push(mn_pq.top());
      mn_pq.pop();
    } else if (mx_pq.size() - mn_pq.size() > 1) {
      mn_pq.push(mx_pq.top());
      mx_pq.pop();
    }
  }

  double findMedian() {
    int sz = mn_pq.size() + mx_pq.size();
    if (sz % 2 == 0)
      return (mn_pq.top() + mx_pq.top()) * 0.5;
    else
      return mx_pq.top();
  }
};
