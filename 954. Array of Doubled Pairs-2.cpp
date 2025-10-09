class Solution {
public:
  bool canReorderDoubled(vector<int> &arr) {
    sort(arr.begin(), arr.end());

    queue<int> q;

    for (auto x : arr)
      if (!q.empty() && (x * 2 == q.front() || q.front() * 2 == x))
        q.pop();
      else
        q.push(x);

    return q.empty();
  }
};