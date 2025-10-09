// heap sort

class Solution {
public:
  vector<int> sortArray(vector<int> &nums) {
    // min heap
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int x : nums)
      pq.push(x);

    vector<int> res;
    while (!pq.empty()) {
      res.push_back(pq.top());
      pq.pop();
    }

    return res;
  }
};