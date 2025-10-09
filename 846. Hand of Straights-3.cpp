class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    int n = hand.size();
    if (n % groupSize)
      return false;
    if (groupSize == 1)
      return true;

    sort(hand.begin(), hand.end());

    queue<pair<int, int>> q; // x, size

    int k = n / groupSize, done = 0;
    for (int i = 0; i < n; ++i) {
      int x = hand[i];
      if (q.empty() || q.front().first + 1 != x) {
        q.push({x, 1});
        continue;
      }
      auto [_, size] = q.front();
      q.pop();
      if (size != groupSize - 1)
        q.push({x, size + 1});
      else
        done++;
    }

    return (done == k);
  }
};