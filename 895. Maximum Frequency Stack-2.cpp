class FreqStack {
public:
  int maxFreq;
  unordered_map<int, int> freq;
  unordered_map<int, stack<int>> fst;
  FreqStack() : maxFreq(0) {}

  void push(int val) {
    maxFreq = max(maxFreq, ++freq[val]);
    fst[freq[val]].push(val);
  }

  int pop() {
    int val = fst[maxFreq].top();
    fst[maxFreq].pop();
    if (fst[maxFreq].size() == 0)
      maxFreq--;
    freq[val]--;
    return val;
  }
};