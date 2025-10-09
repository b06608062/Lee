class Solution {
public:
  int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());

    int l = 0, r = people.size() - 1, res = 0;
    while (l <= r) {
      if (people[l] + people[r] <= limit)
        l++;
      r--;
      res++;
    }

    return res;
  }
};