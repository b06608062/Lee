class Solution {
public:
  int minimumBoxes(vector<int> &apple, vector<int> &capacity) {
    sort(capacity.rbegin(), capacity.rend());

    int res = 0, cap = 0;
    for (auto &a : apple) {
      while (cap < a)
        cap += capacity[res++];
      cap -= a;
    }

    return res;
  }
};