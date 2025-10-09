// 差分陣列 + 掃描
class Solution {
public:
  bool canReach(string s, int minJump, int maxJump) {
    if (s.back() == '1')
      return false;
    int n = s.size();

    vector<int> diff(n, 0);

    int reach = 0;
    diff[0] = 1;
    diff[1] = -1;
    for (int i = 0; i < n; ++i) {
      reach += diff[i];
      if (reach == 0 || s[i] == '1')
        continue;
      if (i + minJump < n)
        diff[i + minJump] += 1;
      if (i + maxJump + 1 < n)
        diff[i + maxJump + 1] -= 1;
    }

    return reach;
  }
};