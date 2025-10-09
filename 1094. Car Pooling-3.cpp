class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    vector<pair<int, int>> events;

    for (auto &t : trips) {
      events.push_back({t[1], t[0]});  // from, +p
      events.push_back({t[2], -t[0]}); // to, -p
    }

    sort(events.begin(), events.end(), [](auto &a, auto &b) {
      if (a.first != b.first)
        return a.first < b.first;
      return a.second < b.second;
    });

    int carry = 0;
    for (auto &e : events) {
      carry += e.second;
      if (carry > capacity)
        return false;
    }

    return true;
  }
};