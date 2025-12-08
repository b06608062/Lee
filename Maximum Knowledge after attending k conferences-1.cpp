// mark
// Maximum Knowledge after attending k conferences
// 事件排序 + 動態維護前 k 大集合
struct Event {
  int day;
  int type; // -1 = remove, +1 = add
  int idx;  // meeting index
};

class Solution {
public:
  int maximumKnowledge(int d, const vector<int> &s, const vector<int> &e,
                       const vector<int> &a, int k) {
    if (k == 0)
      return 0;

    int n = s.size();

    // 建立 2n 個事件：開始、結束+1
    vector<Event> ev;
    ev.reserve(2 * n);
    for (int i = 0; i < n; ++i) {
      ev.push_back({s[i], +1, i});     // start
      ev.push_back({e[i] + 1, -1, i}); // end (在 e+1 這天移除)
    }

    // 排序：依 day，若同一天先處理 remove(-1)，再 add(+1)
    sort(ev.begin(), ev.end(), [](const Event &x, const Event &y) {
      if (x.day != y.day)
        return x.day < y.day;
      return x.type < y.type; // -1 < +1
    });

    using P = pair<int, int>; // (a[i], idx)

    // big：目前已選的前 k 大，依 a[i] 升序（小根堆效果）
    set<P> big;

    // small：其他候補，依 a[i] 降序（大根堆效果）
    struct CmpDesc {
      bool operator()(const P &x, const P &y) const {
        if (x.first != y.first)
          return x.first > y.first; // 倒序
        return x.second < y.second;
      }
    };
    set<P, CmpDesc> small;

    int curSum = 0; // big 裡的總知識
    int res = 0;

    // 把會議 i 加入現在的可選集合
    auto addMeeting = [&](int i) {
      P key = {a[i], i};
      if (big.size() < k) {
        big.insert(key);
        curSum += a[i];
      } else {
        // big 已滿 k 個，看看能不能擠進前 k
        auto itMinBig = big.begin(); // 最小的那個
        if (itMinBig->first < a[i]) {
          // 把最小的丟到 small
          P removed = *itMinBig;
          big.erase(itMinBig);
          curSum -= removed.first;
          small.insert(removed);

          // 新的放進 big
          big.insert(key);
          curSum += a[i];
        } else {
          // 進不了前 k，丟 small
          small.insert(key);
        }
      }
    };

    // 把會議 i 從現在的可選集合移除
    auto removeMeeting = [&](int i) {
      P key = {a[i], i};

      // 先看在 big 裡面
      auto itBig = big.find(key);
      if (itBig != big.end()) {
        // 從 big 移除
        curSum -= a[i];
        big.erase(itBig);

        // 從 small 裡補一個最大值進來（如果有，而且 k > 0）
        if (!small.empty()) {
          auto itMaxSmall = small.begin(); // 因為 small 是降序
          P pulled = *itMaxSmall;
          small.erase(itMaxSmall);

          big.insert(pulled);
          curSum += pulled.first;
        }
      } else {
        // 不在 big，就應該在 small 裡面
        auto itSmall = small.find(key);
        if (itSmall != small.end()) {
          small.erase(itSmall);
        }
      }
    };

    // 掃描所有事件
    int iEv = 0;
    int m = ev.size();

    while (iEv < m) {
      int day = ev[iEv].day;

      // 同一天的事件全部處理完
      while (iEv < m && ev[iEv].day == day) {
        if (ev[iEv].type == -1) {
          removeMeeting(ev[iEv].idx);
        } else { // +1
          addMeeting(ev[iEv].idx);
        }
        ++iEv;
      }

      // 只有在 1..d 的天數才是會議實際進行的天
      if (day >= 1 && day <= d) {
        res = max(res, curSum);
      } else
        break; // 超過 d 天就不用繼續了
    }

    return res;
  }
};
