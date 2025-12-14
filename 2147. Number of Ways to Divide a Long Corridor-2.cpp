// mark
// 1915
// 乘法原理
class Solution {
public:
  int numberOfWays(string corridor) {
    const int MOD = 1e9 + 7;
    // 先數總 seats
    int totalS = 0;
    for (char c : corridor)
      if (c == 'S')
        totalS++;
    if (totalS == 0 || totalS % 2 == 1)
      return 0;

    long long res = 1;
    int seats = 0, plantsBetween = 0;
    bool betweenGroups = false; // 是否已經完成一組(2 seats)並在等下一組的第一張
    for (char c : corridor) {
      if (c == 'S') {
        seats++;
        if (seats % 2 == 0) {
          // 完成一組
          betweenGroups = true;
          plantsBetween = 0;
        } else {
          // 這是下一組的第一張椅子
          res = res * (plantsBetween + 1) % MOD;
          betweenGroups = false;
        }
      } else // 'P'
        if (betweenGroups)
          plantsBetween++;
    }
    return (int)res;
  }
};
