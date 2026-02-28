class Solution {
public:
  int numSteps(string s) {
    int n = s.size();
    int step = 0, carry = 0;
    for (int i = n - 1; i > 0; --i) {
      int bit = s[i] - '0';
      step += 1 + (bit ^ carry);
      carry |= bit;
    }

    return step + carry;
  }
};