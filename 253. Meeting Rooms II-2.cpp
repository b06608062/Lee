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
    map<int, int> mmap;
    for (auto [start, end] : intervals) {
      mmap[start]++;
      mmap[end]--;
    }

    int cur = 0, res = 0;
    for (auto [k, v] : mmap) {
      cur += v;
      res = max(res, cur);
    }

    return res;
  }
};