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
    vector<pair<int, int>> events;
    for (auto [start, end] : intervals) {
      events.push_back({start, +1});
      events.push_back({end, -1});
    }

    sort(events.begin(), events.end(), [](auto &a, auto &b) {
      if (a.first != b.first)
        return a.first < b.first;
      return a.second < b.second;
    });

    int cur = 0, res = 0;
    for (auto [_, x] : events) {
      cur += x;
      res = max(res, cur);
    }

    return res;
  }
};