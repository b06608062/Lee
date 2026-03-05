class Solution {
public:
  int minOperations(string s) {
    int n = s.size();
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; ++i) {
      int b = s[i] - '0';
      cnt0 += (i % 2) ^ b;
      cnt1 += (i % 2) ^ (1 - b);
    }
    return min(cnt0, cnt1);
  }
};