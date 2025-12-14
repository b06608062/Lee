// mark
// 排序事件發生時間 + 使用 pq 來維護目前高度 + Lazy 刪除
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
    unordered_set<int> in;
    // max heap
    priority_queue<pair<int, int>> pq; // h, idx

    int prev = 0;
    for (auto &[h, t, idx] : evs) {
      if (h < 0) {
        if (-h > prev) {
          prev = -h;
          res.push_back({t, -h});
        }
        in.insert(idx);
        pq.push({-h, idx});
      } else {
        in.erase(idx);
        while (!pq.empty() && !in.count(pq.top().second))
          pq.pop();
        int next = pq.empty() ? 0 : pq.top().first;
        if (prev != next) {
          prev = next;
          res.push_back({t, next});
        }
      }
    }

    return res;
  }
};

struct Event {
  int h, t, o;
};

class Solution {
public:
  vector<vector<int>> getSkyline(vector<vector<int>> &buildings) {
    int n = buildings.size();

    vector<Event> evs;
    for (int i = 0; i < n; ++i) {
      auto &b = buildings[i];
      int t0 = b[0], t1 = b[1], h = b[2];
      evs.push_back({-h, t0, t1});
      evs.push_back({h, t1, t1});
    }

    sort(evs.begin(), evs.end(), [](auto &a, auto &b) {
      if (a.t != b.t)
        return a.t < b.t;
      return a.h < b.h;
    });

    vector<vector<int>> res;
    // max heap
    priority_queue<pair<int, int>> pq; // h, t

    int prev = 0;
    for (auto &[h, t, o] : evs) {
      if (h < 0) {
        if (-h > prev) {
          prev = -h;
          res.push_back({t, -h});
        }
        pq.push({-h, o});
      } else {
        while (!pq.empty() && pq.top().second <= o)
          pq.pop();
        int next = pq.empty() ? 0 : pq.top().first;
        if (prev != next) {
          prev = next;
          res.push_back({t, next});
        }
      }
    }

    return res;
  }
};