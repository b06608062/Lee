class MedianFinder {
public:
  priority_queue<int, vector<int>, greater<int>> minPq;
  priority_queue<int, vector<int>, less<int>> maxPq;
  MedianFinder() {}

  void addNum(int num) {
    if (maxPq.empty() || num <= maxPq.top())
      maxPq.push(num);
    else
      minPq.push(num);

    if (minPq.size() > maxPq.size()) {
      maxPq.push(minPq.top());
      minPq.pop();
    } else if (maxPq.size() - 1 > minPq.size()) {
      minPq.push(maxPq.top());
      maxPq.pop();
    }
  }

  double findMedian() {
    int m = maxPq.size(), n = minPq.size();
    if ((m + n) % 2)
      return maxPq.top();
    return (maxPq.top() + minPq.top()) * 0.5;
  }
};