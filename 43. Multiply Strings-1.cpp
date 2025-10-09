class Solution {
public:
  string multiply(string num1, string num2) {
    int n1 = num1.size(), n2 = num2.size();

    vector<int> muls(n1 + n2, 0);
    for (int i = n1 - 1; i >= 0; --i)
      for (int j = n2 - 1; j >= 0; --j) {
        int mul = (num1[i] - '0') * (num2[j] - '0');
        int pos1 = muls[i + j], pos2 = muls[i + j + 1];
        int sum = pos1 * 10 + pos2 + mul;
        muls[i + j] = sum / 10;
        muls[i + j + 1] = sum % 10;
      }

    string res;
    for (auto x : muls) {
      if (res.empty() && x == 0)
        continue;
      res.push_back(x + '0');
    }

    return res.empty() ? "0" : res;
  }
};