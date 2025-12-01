// TLE
class Solution {
public:
  long long maxRunTime(int n, vector<int> &batteries) {
    priority_queue<int> pq;
    for (auto b : batteries)
      pq.push(b);

    long long res = 0;
    while (!pq.empty()) {
      vector<int> temp;
      int k = n;
      while (k && !pq.empty()) {
        k--;
        int b = pq.top();
        pq.pop();
        if (--b)
          temp.push_back(b);
      }
      if (k)
        break;
      res++;
      for (auto b : temp)
        pq.push(b);
    }

    return res;
  }
};