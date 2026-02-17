class Solution {
public:
  vector<string> res;
  vector<int> subset;
  vector<string> readBinaryWatch(int turnedOn) {
    subset.resize(10);
    dfs(0, turnedOn);

    return res;
  }

  void dfs(int i, int on) {
    if (i >= 10 || on == 0) {
      if (on == 0) {
        int hour = 0, min = 0;
        for (int i = 0; i < 4; ++i)
          if (subset[i])
            hour |= 1 << i;
        for (int j = 4; j < 10; ++j)
          if (subset[j])
            min |= 1 << (j - 4);
        if (hour < 12 && min < 60)
          res.push_back(to_string(hour) + ":" +
                        (min < 10 ? "0" + to_string(min) : to_string(min)));
      }
      return;
    }
    subset[i] = 1;
    dfs(i + 1, on - 1);
    subset[i] = 0;
    dfs(i + 1, on);
  }
};