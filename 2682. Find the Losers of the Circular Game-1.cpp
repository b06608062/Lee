class Solution {
public:
  vector<int> circularGameLosers(int n, int k) {
    vector<bool> get(n, false);

    int cur = 0, round = 0;
    while (true) {
      if (get[cur])
        break;
      else
        get[cur] = true;
      round++;
      cur = (cur + k * round) % n;
    }

    vector<int> res;
    for (int i = 0; i < n; ++i)
      if (!get[i])
        res.push_back(i + 1);

    return res;
  }
};