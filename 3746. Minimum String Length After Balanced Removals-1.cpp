class Solution {
public:
  int minLengthAfterRemovals(string s) {
    int cntA = 0, cntB = 0;
    for (auto ch : s)
      if (ch == 'a')
        cntA++;
      else
        cntB++;
    return abs(cntA - cntB);
  }
};