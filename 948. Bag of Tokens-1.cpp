class Solution {
public:
  int bagOfTokensScore(vector<int> &tokens, int power) {
    sort(tokens.begin(), tokens.end());

    int cur = 0, res = 0;
    int l = 0, r = tokens.size() - 1;
    while (l <= r) {
      if (tokens[l] <= power) {
        cur++;
        power -= tokens[l++];
      } else {
        cur--;
        power += tokens[r--];
      }
      if (cur < 0)
        return res;
      res = max(res, cur);
    }

    return res;
  }
};