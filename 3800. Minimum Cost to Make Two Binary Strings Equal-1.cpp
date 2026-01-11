// mark
// 1841
// 貪心構造題
class Solution {
public:
  long long minimumCost(string s, string t, int flipCost, int swapCost,
                        int crossCost) {
    int n = s.size();
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i)
      if (s[i] != t[i])
        if (s[i] == '0')
          a++;
        else
          b++;

    long long res = 1ll * min(swapCost, 2 * flipCost) * min(a, b);
    int r = abs(a - b);
    res += 1ll * min(swapCost + crossCost, 2 * flipCost) * (r / 2);
    if (r % 2)
      res += flipCost;
    return res;
  }
};