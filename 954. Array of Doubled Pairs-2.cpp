// mark
// 1548
// 貪心 + 依絕對值排序 + 隊列配對
class Solution {
public:
  bool canReorderDoubled(vector<int> &arr) {
    sort(arr.begin(), arr.end(), [](auto &a, auto &b) {
      if (abs(a) == abs(b))
        return a < b;
      return abs(a) < abs(b);
    });

    queue<int> q;
    for (auto x : arr) {
      if (!q.empty() && q.front() * 2 == x)
        q.pop();
      else
        q.push(x);
    }

    return q.empty();
  }
};