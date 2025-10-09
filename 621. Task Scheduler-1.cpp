class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {
    vector<int> freq(26, 0);

    for (char task : tasks)
      freq[task - 'A']++;

    int maxFreq = 0;
    for (int f : freq)
      maxFreq = max(maxFreq, f);

    int maxFreqCount = 0;
    for (int f : freq)
      if (f == maxFreq)
        maxFreqCount++;

    return max((maxFreq - 1) * (n + 1) + maxFreqCount, (int)tasks.size());
  }
};