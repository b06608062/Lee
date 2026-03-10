class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    bitset<3001> f;
    f[0] = 1;
    int sum = 0;
    for (auto x : stones) {
      sum += x;
      f |= f << x;
    }

    for (int i = sum / 2; i >= 0; --i)
      if (f[i])
        return (sum - i) - i;
    return -1;
  }
};