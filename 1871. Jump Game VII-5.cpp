// BFS + 去重
class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    if (s.back() == '1')
      return false;

    queue<int> q;

    q.push(0);
    int nextStart = 1; // 全域尚未掃描的最左位置
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      int L = max(i + minJump, nextStart);
      int R = min(i + maxJump, n - 1);
      for (int j = L; j <= R; ++j) {
        if (s[j] == '0') {
          if (j == n - 1)
            return true;
          q.push(j);
        }
      }
      nextStart = R + 1;
    }

    return false;
  }
};
