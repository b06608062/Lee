// mark
// 2006
// 字串環狀結構 (s + s) + 前後綴

class Solution {
public:
  int minFlips(string s) {
    int n = s.size();
    // preA[i]: 前 i 個字元變成 0101... 的成本
    // preB[i]: 前 i 個字元變成 1010... 的成本
    vector<int> preA(n + 1, 0), preB(n + 1, 0);
    // sufA[i]: 從 i 到末尾變成 0101... 的成本
    // sufB[i]: 從 i 到末尾變成 1010... 的成本
    vector<int> sufA(n + 1, 0), sufB(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      int b = s[i - 1] - '0';
      preA[i] = preA[i - 1] + (((i - 1) % 2) ^ b);
      preB[i] = preB[i - 1] + (((i - 1) % 2) ^ (1 - b));
    }

    for (int i = n - 1; i >= 0; --i) {
      int b = s[i] - '0';
      sufA[i] = sufA[i + 1] + ((i % 2) ^ b);
      sufB[i] = sufB[i + 1] + ((i % 2) ^ (1 - b));
    }

    int res = min(preA[n], preB[n]);

    if (n % 2 == 1)
      for (int i = 1; i < n; ++i)
        res = min({res, sufA[i] + preB[i], sufB[i] + preA[i]});

    return res;
  }
};