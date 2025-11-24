class Solution {
public:
  int totalWaviness(int num1, int num2) {
    int res = 0;
    for (int i = num1; i <= num2; ++i) {
      string x = to_string(i);
      int sz = x.size();
      for (int j = 1; j < sz - 1; ++j)
        if (x[j] > x[j - 1] && x[j] > x[j + 1])
          res++;
        else if (x[j] < x[j - 1] && x[j] < x[j + 1])
          res++;
    }

    return res;
  }
};