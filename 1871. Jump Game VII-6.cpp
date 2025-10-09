// 問最短到達步數
class Solution {
public:
  int minJumps(string s, int minJump, int maxJump) {
    int n = s.size();
    if (s.back() == '1')
      return -1;

    queue<int> q;

    q.push(0);
    int nextStart = 1, res = 0;
    while (!q.empty()) {
      res++;
      int size = q.size();
      while (size--) {
        int i = q.front();
        q.pop();
        int L = max(i + minJump, nextStart);
        int R = min(i + maxJump, n - 1);
        for (int j = L; j <= R; ++j) {
          if (s[j] == '0') {
            if (j == n - 1)
              return res;
            q.push(j);
          }
        }
        nextStart = R + 1;
      }
    }

    return -1;
  }
};
