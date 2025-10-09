class Solution {
public:
  long long minTime(vector<int> &skill, vector<int> &mana) {
    int n = skill.size();

    vector<long long> done(n, 0);

    for (auto x : mana) {
      vector<long long> pref(n + 1, 0);
      long long now = done[0];
      for (int i = 1; i < n; ++i) {
        pref[i] = pref[i - 1] + skill[i - 1] * x;
        now = max(now, done[i] - pref[i]);
      }
      pref[n] = pref[n - 1] + skill[n - 1] * x;
      for (int i = 0; i < n; ++i)
        done[i] = now + pref[i + 1];
    }

    return done[n - 1];
  }
};