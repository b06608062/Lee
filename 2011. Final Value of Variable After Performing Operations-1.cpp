class Solution {
public:
  int finalValueAfterOperations(vector<string> &operations) {
    int X = 0;
    for (auto &op : operations)
      if (op == "X++" || op == "++X")
        X += 1;
      else
        X -= 1;

    return X;
  }
};