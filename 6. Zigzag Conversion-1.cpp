class Solution {
public:
  string convert(string s, int numRows) {
    if (numRows == 1)
      return s;
    vector<string> rows(numRows);
    int i = 0, turn = 1;
    for (char ch : s) {
      rows[i] += ch;
      int nxt = i + turn;
      if (nxt >= 0 && nxt < numRows) {
        i = nxt;
      } else {
        turn *= -1;
        i += turn;
      }
    }

    string res = "";
    for (auto &row : rows) {
      for (char &ch : row) {
        res += ch;
      }
    }

    return res;
  }
};