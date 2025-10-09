class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    int n = hand.size();
    if (n % groupSize)
      return false;

    map<int, int> mmap;
    for (auto x : hand)
      mmap[x]++;

    while (!mmap.empty()) {
      auto [x, cnt] = *mmap.begin();
      for (int i = x; i < x + groupSize; ++i) {
        if ((mmap[i] -= cnt) < 0)
          return false;
        if (mmap[i] == 0)
          mmap.erase(i);
      }
    }

    return true;
  }
};