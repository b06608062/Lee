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
    vector<int> xs;
    for (auto [start, end] : intervals) {
      xs.push_back(start);
      xs.push_back(end);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());

    unordered_map<int, int> umap;
    for (int i = 0; i < xs.size(); ++i)
      umap[xs[i]] = i;

    vector<int> diff(xs.size(), 0);
    for (auto [start, end] : intervals) {
      diff[umap[start]]++;
      diff[umap[end]]--;
    }

    int cur = 0, res = 0;
    for (auto x : diff) {
      cur += x;
      res = max(res, cur);
    }

    return res;
  }
};