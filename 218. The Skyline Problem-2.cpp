// mark
// 排序事件發生時間 + 使用 set 來維護目前高度
// 經典掃描線題
struct Event {
  int h, t, idx;
};

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    int n = buildings.size();

    vector<Event> evs;
    for (int i = 0; i < n; ++i) {
      auto &b = buildings[i];
      int t0 = b[0], t1 = b[1], h = b[2];
      evs.push_back({-h, t0, i});
      evs.push_back({h, t1, i});
    }

    sort(evs.begin(), evs.end(), [](auto &a, auto &b) {
      if (a.t != b.t)
        return a.t < b.t;
      return a.h < b.h;
    });

    vector<vector<int>> res;
    set<pair<int, int>> sset;

    int prev = 0;
    for (auto &[h, t, idx] : evs) {
      if (h < 0) {
        if (-h > prev) {
          prev = -h;
          res.push_back({t, -h});
        }
        sset.insert({-h, idx});
      } else {
        sset.erase({h, idx});
        int next = sset.empty() ? 0 : sset.rbegin()->first;
        if (next != prev) {
          prev = next;
          res.push_back({t, next});
        }
      }
    }

    return res;
  }
};