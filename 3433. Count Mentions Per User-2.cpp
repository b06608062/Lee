// mark
// 1745
// 事件排序 + 最小堆回線 + Lazy Update 延遲更新
// ALL / HERE O(1) 更新
// 延遲更新時間點 : 下線時間 & 答案返回前
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
    for (auto &ev : events)
      evs.push_back({ev[0] == "OFFLINE" ? 0 : 1, stoi(ev[1]), ev[2]});

    sort(evs.begin(), evs.end(), [](auto &a, auto &b) {
      if (a.time != b.time)
        return a.time < b.time;
      return a.type < b.type;
    });

    // min heap
    using P = pair<int, int>; // time, id
    priority_queue<P, vector<P>, greater<P>> pq;

    vector<int> res(n, 0);
    vector<int> lastHere(n, 0);
    int hereCnt = 0, allCnt = 0;
    for (auto &[type, time, str] : evs) {
      while (!pq.empty() && pq.top().first <= time) {
        int id = pq.top().second;
        onlines[id] = true;
        lastHere[id] = hereCnt;
        pq.pop();
      }
      if (type == 0) {
        int id = stoi(str);
        onlines[id] = false;
        res[id] += hereCnt - lastHere[id];
        lastHere[id] = hereCnt;
        pq.push({time + 60, id});
      } else {
        if (str == "ALL")
          allCnt++;
        else if (str == "HERE")
          hereCnt++;
        else {
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

    for (int i = 0; i < n; ++i)
      res[i] += allCnt + (onlines[i] ? hereCnt - lastHere[i] : 0);

    return res;
  }
};