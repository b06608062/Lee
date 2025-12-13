struct Event {
  int type, time;
  string str;
};

class Solution {
public:
  vector<int> countMentions(int numberOfUsers, vector<vector<string>> &events) {
    int n = numberOfUsers;
    vector<bool> onlines(n, true);
    vector<Event> evs;
    for (auto &ev : events) {
      if (ev[0] == "OFFLINE")
        evs.push_back({0, stoi(ev[1]), ev[2]});
      else
        evs.push_back({1, stoi(ev[1]), ev[2]});
    }

    sort(evs.begin(), evs.end(), [](auto &a, auto &b) {
      if (a.time != b.time)
        return a.time < b.time;
      return a.type < b.type;
    });

    using P = pair<int, int>; // time, id
    // min heap
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<int> res(n, 0);
    for (auto &[type, time, str] : evs) {
      while (!pq.empty() && pq.top().first <= time) {
        onlines[pq.top().second] = true;
        pq.pop();
      }
      if (type == 0) {
        int id = stoi(str);
        onlines[id] = false;
        pq.push({time + 60, id});
      } else {
        if (str == "ALL") {
          for (auto &x : res)
            x++;
        } else if (str == "HERE") {
          for (int i = 0; i < n; ++i)
            if (onlines[i])
              res[i]++;
        } else {
          int i = 0, sz = str.size();
          while (i < sz) {
            int j = str.find(' ', i);
            if (j == string::npos)
              j = sz;
            int id = stoi(str.substr(i + 2, j - (i + 2)));
            res[id]++;
            i = j + 1;
          }
        }
      }
    }

    return res;
  }
};