class Solution {
public:
  int minAllOneMultiple(int k) {

    int cur = 0;
    for (int i = 0; i <= k; ++i) {
      cur = (cur * 10 + 1) % k;
      if (cur == 0)
        return i + 1;
    }

    return -1;
  }
};