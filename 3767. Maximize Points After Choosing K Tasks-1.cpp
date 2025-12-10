class Solution {
public:
  long long maxPoints(vector<int> &technique1, vector<int> &technique2, int k) {
    int n = technique1.size();
    long long res = 0;
    vector<int> diff;
    for (int i = 0; i < n; ++i) {
      int x1 = technique1[i], x2 = technique2[i];
      if (x1 >= x2) {
        res += x1;
        k--;
      } else {
        res += x2;
        diff.push_back(x2 - x1);
      }
    }

    if (k > 0) {
      sort(diff.begin(), diff.end());
      for (auto d : diff) {
        res -= d;
        if (--k == 0)
          break;
      }
    }

    return res;
  }
};