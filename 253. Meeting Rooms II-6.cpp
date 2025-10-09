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
    int n = intervals.size();

    vector<int> starts, ends;
    for (auto [start, end] : intervals) {
      starts.push_back(start);
      ends.push_back(end);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());

    int i = 0, j = 0, room = 0, res = 0;
    while (i < n) {
      if (starts[i] < ends[j])
        room++, i++;
      else
        room--, j++;
      res = max(res, room);
    }

    return res;
  }
};
