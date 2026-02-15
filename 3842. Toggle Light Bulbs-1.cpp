class Solution {
public:
  vector<int> toggleLightBulbs(vector<int> &bulbs) {
    vector<int> f(101, 0);
    for (auto b : bulbs)
      f[b] = !f[b];
    vector<int> res;
    for (int i = 1; i <= 100; ++i)
      if (f[i])
        res.push_back(i);

    return res;
  }
};