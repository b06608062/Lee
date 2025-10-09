class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    int freq[26] = {0};

    for (auto t : tasks)
      freq[t - 'A']++;

    priority_queue<int> pq;
    for (auto f : freq)
      if (f)
        pq.push(f);

    int res = 0;
    while (!pq.empty()) {
      int k = n + 1;
      vector<int> temp;
      while (k > 0 && !pq.empty()) {
        int f = pq.top();
        pq.pop();
        if (--f > 0)
          temp.push_back(f);
        res++;
        k--;
      }

      for (auto f : temp)
        pq.push(f);

      if (!pq.empty())
        res += k;
    }

    return res;
  }
};