class ExamTracker {
public:
  vector<long long> pref;
  vector<int> ti;
  ExamTracker() { pref.push_back(0); }

  void record(int time, int score) {
    pref.push_back(pref.back() + score);
    ti.push_back(time);
  }

  long long totalScore(int startTime, int endTime) {
    int l = lower_bound(ti.begin(), ti.end(), startTime) - ti.begin();
    int r = upper_bound(ti.begin(), ti.end(), endTime) - ti.begin();
    // int r = lower_bound(ti.begin(), ti.end(), endTime + 1) - ti.begin();
    if (r == 0)
      return 0;
    return pref[r] - pref[l];
  }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */