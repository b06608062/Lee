class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    vector<int> diff(1001, 0);

    for (auto &t : trips) {
      int people = t[0], from = t[1], to = t[2];
      diff[from] += people;
      diff[to] -= people;
    }

    int cur = 0;
    for (int x = 0; x <= 1000; ++x) {
      cur += diff[x];
      if (cur > capacity)
        return false;
    }

    return true;
  }
};
