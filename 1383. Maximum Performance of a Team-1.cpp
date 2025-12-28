// mark
// 2091
// efficiency 降序 + 維護前 k 大 speed 和
class Solution {
public:
  int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency,
                     int k) {
    const int MOD = 1e9 + 7;

    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; ++i)
      arr[i] = {efficiency[i], speed[i]};

    sort(arr.begin(), arr.end(),
         [](auto &a, auto &b) { return a.first > b.first; });

    // min
    priority_queue<int, vector<int>, greater<int>> pq;
    long long curSum = 0, res = 0;
    for (auto &[e, f] : arr) {
      curSum += f;
      pq.push(f);
      if (pq.size() > k) {
        curSum -= pq.top();
        pq.pop();
      }
      res = max(res, curSum * e);
    }

    return res % MOD;
  }
};