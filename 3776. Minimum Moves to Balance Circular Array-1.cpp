class Solution {
public:
  long long minMoves(vector<int> &balance) {
    long long sum = accumulate(balance.begin(), balance.end(), 0ll);
    if (sum < 0)
      return -1;

    int n = balance.size();
    vector<pair<int, int>> arr;
    int negIdx = -1;
    for (int i = 0; i < n; ++i) {
      int x = balance[i];
      if (x < 0)
        negIdx = i;
      arr.push_back({max(0, x), i});
    }

    if (negIdx == -1)
      return 0;

    sort(arr.begin(), arr.end(), [&](auto &a, auto &b) {
      int ai = a.second, bi = b.second;
      return min(abs(ai - negIdx), n - abs(ai - negIdx)) <
             min(abs(bi - negIdx), n - abs(bi - negIdx));
    });

    long long res = 0;
    int k = -balance[negIdx];
    for (int i = 0; i < n && k > 0; ++i) {
      auto [x, idx] = arr[i];
      int d = min(abs(idx - negIdx), n - abs(idx - negIdx));
      int used = min(x, k);
      k -= used;
      res += 1ll * d * used;
    }

    return res;
  }
};