// Maximum Knowledge after attending k conferences
struct Event {
  long long day;
  int type; // -1 = remove, +1 = add
  int idx;  // meeting index
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long d;
  int n;
  int k;
  if (!(cin >> d >> n >> k))
    return 0;

  vector<long long> s(n), e(n), a(n);
  for (int i = 0; i < n; ++i) {
    cin >> s[i] >> e[i] >> a[i];
  }

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

  using P = pair<long long, int>; // (a[i], idx)

  // big：目前已選的前 k 大，依 a[i] 升序（小根堆效果）
  multiset<P> big;

  // small：其他候補，依 a[i] 降序（大根堆效果）
  struct CmpDesc {
    bool operator()(const P &x, const P &y) const {
      if (x.first != y.first)
        return x.first > y.first; // 倒序
      return x.second < y.second;
    }
  };
  multiset<P, CmpDesc> small;

  long long curSum = 0; // big 裡的總知識
  long long ans = 0;

  // 把會議 i 加入現在的可選集合
  auto addMeeting = [&](int i) {
    P key = {a[i], i};
    if (k == 0) {
      // 不能參加任何會議，全部放 small 即可
      small.insert(key);
      return;
    }

    if ((int)big.size() < k) {
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
      if (k > 0 && !small.empty()) {
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
      // 理論上一定會找到；如果沒找到就代表哪裡邏輯出錯
    }
  };

  // 掃描所有事件
  int iEv = 0;
  int m = (int)ev.size();

  while (iEv < m) {
    long long day = ev[iEv].day;

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
      ans = max(ans, curSum);
    }
    // day > d (例如 d+1) 就只是把最後一天的會議移除，不需要更新答案
  }

  cout << ans << '\n';
  return 0;
}
