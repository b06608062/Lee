// mark
// 用 map 維護「互不重疊」的半開區間 [l, r)
// 處理值域很大的區間追蹤問題
class RangeModule {
public:
  // 所有已追蹤的區間（已合併、互不重疊）
  map<int, int> mmap;
  RangeModule() {}

  // 加入追蹤區間 [left, right)
  void addRange(int left, int right) {
    auto it = mmap.upper_bound(left);

    // 檢查起點 <= left 的最後一段
    if (it != mmap.begin()) {
      auto pre = prev(it);
      if (pre->second >= left) // 重疊/相接
        it = pre;              // 從這段開始合併刪除
    }

    // 往右吃掉所有重疊/相接的區間
    while (it != mmap.end() && it->first <= right) {
      left = min(left, it->first);
      right = max(right, it->second);
      it = mmap.erase(it);
    }

    mmap[left] = right;
  }

  // 查詢 [left, right) 是否「完全」被追蹤
  bool queryRange(int left, int right) {
    // 找第一個「起點 > left」的區間，答案只可能在它的前一段
    auto it = mmap.upper_bound(left);
    if (it == mmap.begin())
      return false; // 沒有任何區間起點 <= left
    it--;

    // 若這段的右端點 >= right，代表 [left,right) 完全包含在這段已追蹤區間內
    return it->second >= right;
  }

  // 移除追蹤區間 [left, right)
  void removeRange(int left, int right) {
    // it = 第一個起點 > left 的區間
    auto it = mmap.upper_bound(left);

    // 先把可能「跨過 left」的前一段納入考慮
    // 因為它的起點 <= left，有可能與 [left,right) 重疊
    if (it != mmap.begin()) {
      auto pre = prev(it);
      if (pre->second > left) // 半開區間：end==left 不算重疊
        it = pre;             // 從這段開始處理
    }

    vector<pair<int, int>> remain;

    // 往右刪掉所有與 [left,right) 有重疊的區間
    // 對半開區間來說，起點 < right 才可能重疊
    while (it != mmap.end() && it->first < right) {
      int L = it->first, R = it->second;
      it = mmap.erase(
          it); // erase 回傳下一個 iterator（C++11 起 map::erase(it) 會回傳）

      // 被挖掉 [left,right) 後，最多留下兩段：
      // 左段 [L, left)
      if (L < left)
        remain.push_back({L, left});
      // 右段 [right, R)
      if (right < R)
        remain.push_back({right, R});
    }

    // 把剩下的區間加回去
    for (auto &seg : remain) {
      mmap[seg.first] = seg.second;
    }
  }
};
