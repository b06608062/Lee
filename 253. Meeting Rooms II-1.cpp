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
    int diff[1000001];
    for (auto [start, end] : intervals) {
      diff[start]++;
      diff[end]--;
    }

    int cur = 0, res = 0;
    for (auto x : diff) {
      cur += x;
      res = max(res, cur);
    }

    return res;
  }
};
