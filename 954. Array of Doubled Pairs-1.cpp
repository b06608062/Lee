class Solution {
public:
  bool canReorderDoubled(vector<int> &arr) {
    map<int, int> mmap1, mmap2;

    int zero = 0;
    for (auto x : arr)
      if (x == 0)
        zero++;
      else if (x > 0)
        mmap1[x]++;
      else
        mmap2[x]++;

    if (zero % 2)
      return false;

    while (!mmap1.empty()) { // positive
      auto [x, f] = *mmap1.begin();
      mmap1.erase(x);
      if (f == 0)
        continue;
      int target = x * 2;
      if (mmap1.count(target) && mmap1[target] >= f)
        mmap1[target] -= f;
      else
        return false;
    }

    while (!mmap2.empty()) { // negative
      auto [x, f] = *mmap2.rbegin();
      mmap2.erase(x);
      if (f == 0)
        continue;
      int target = x * 2;
      if (mmap2.count(target) && mmap2[target] >= f)
        mmap2[target] -= f;
      else
        return false;
    }

    return true;
  }
};