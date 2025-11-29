class MedianFinder {
public:
  multiset<int> s;
  multiset<int>::iterator mid;

  MedianFinder() {}

  void addNum(int num) {
    if (s.empty()) {
      s.insert(num);
      mid = s.begin();
      return;
    }

    int n = s.size();
    s.insert(num);

    if (n % 2 == 1) {
      // 原本是奇數，插入後變偶數，mid 要指向「左中位」
      if (num < *mid) {
        // 新數插到 mid 左邊，左邊變多一個，左中位會往左移
        mid--;
      }
      // 否則插在右邊或 mid 位置右邊，左中位仍然是原本的 mid
    } else {
      // 原本是偶數，插入後變奇數，要讓 mid 指到中間那個
      if (num >= *mid) {
        // 新數插到 mid 右邊，真正的中位會往右移
        mid++;
      }
      // 否則插在 mid 左邊，原本的 mid 會變成正中間，不動即可
    }
  }

  double findMedian() {
    int n = s.size();
    if (n % 2 == 1) {
      return *mid;
    } else {
      auto nextMid = next(mid);
      return ((double)*mid + (double)*nextMid) * 0.5;
    }
  }
};
