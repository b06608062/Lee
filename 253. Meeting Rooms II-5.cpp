// NeetCode
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
  int minMeetingRooms(vector<Interval> &intervals) {
    sort(intervals.begin(), intervals.end(),
         [](auto &a, auto &b) { return a.start < b.start; });

    // min heap
    priority_queue<int, vector<int>, greater<int>> pq; // end

    int res = 0;
    for (auto [start, end] : intervals) {
      while (!pq.empty() && pq.top() <= start)
        pq.pop();
      pq.push(end);
      res = max(res, (int)pq.size());
    }

    return res;
  }
};