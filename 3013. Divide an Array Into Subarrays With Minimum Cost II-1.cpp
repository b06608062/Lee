// mark
// 2540
// 滑動窗口 + 維護兩個有序集合 L, R

class Solution {
public:
  long long minimumCost(vector<int> &nums, int k, int dist) {
    int n = nums.size();
    long long cur = 0;
    multiset<int> mset1, mset2;
    int tsz = k - 1;

    auto balance = [&]() {
      while (mset1.size() < tsz && !mset2.empty()) {
        int x = *mset2.begin();
        cur += x;
        mset1.insert(x);
        mset2.erase(mset2.begin());
      }
      while (mset1.size() > tsz) {
        int x = *mset1.rbegin();
        cur -= x;
        mset2.insert(x);
        mset1.erase(prev(mset1.end()));
      }
    };

    for (int i = 1; i <= dist + 1; ++i) {
      mset2.insert(nums[i]);
    }
    balance();

    long long res = cur;

    for (int i = dist + 2; i < n; ++i) {
      int out = nums[i - dist - 1];
      auto it1 = mset1.find(out);
      if (it1 != mset1.end()) {
        cur -= out;
        mset1.erase(it1);
      } else {
        mset2.erase(mset2.find(out));
      }

      int in = nums[i];
      if (in < *mset1.rbegin()) {
        mset1.insert(in);
        cur += in;
      } else {
        mset2.insert(in);
      }

      balance();

      res = min(res, cur);
    }

    return res + nums[0];
  }
};