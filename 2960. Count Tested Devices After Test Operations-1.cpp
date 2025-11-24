class Solution {
public:
  int countTestedDevices(vector<int> &batteryPercentages) {
    int res = 0;
    for (auto x : batteryPercentages) {
      if (x - res > 0)
        res++;
    }

    return res;
  }
};