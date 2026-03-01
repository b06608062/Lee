// mark
// ???
// 看成完全圖，n 個點，每兩個點之間的邊權重為 1
// 連接 n 個點的邊權重和為 n * (n - 1) / 2
// 要去除所有邊，必須把 n 個點分成 n 組，每組 1 個點

class Solution {
public:
  int minCost(int n) { return n * (n - 1) / 2; }
};