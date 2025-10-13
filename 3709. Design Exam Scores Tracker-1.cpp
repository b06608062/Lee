class ExamTracker {
public:
  vector<int> times;
  vector<long long> pref;
  ExamTracker() { pref.push_back(0); }

  void record(int time, int score) {
    times.push_back(time);
    pref.push_back(pref.back() + score);
  }

  long long totalScore(int startTime, int endTime) {
    int lo = lower_bound(times.begin(), times.end(), startTime) - times.begin();
    int up =
        upper_bound(times.begin(), times.end(), endTime) - times.begin() - 1;

    return pref[up + 1] - pref[lo];
  }
};
