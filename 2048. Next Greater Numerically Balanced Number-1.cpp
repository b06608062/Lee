// mark
// 1734
// Backtracking + 數位枚舉
class Solution {
public:
  set<int> sset;
  int count[7];
  int nextBeautifulNumber(int n) {
    dfs(0);

    for (int x : sset)
      if (x > n)
        return x;

    return -1;
  }

private:
  void dfs(int cur) {
    if (cur > 1224444)
      return;
    if (cur > 0 && isBeautiful())
      sset.insert(cur);

    for (int d = 1; d <= 6; ++d)
      if (count[d] < d) {
        count[d]++;
        dfs(cur * 10 + d);
        count[d]--;
      }
  }

  bool isBeautiful() {
    for (int d = 1; d <= 6; ++d)
      if (count[d] != 0 && count[d] != d)
        return false;
    return true;
  }
};