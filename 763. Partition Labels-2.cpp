class Solution {
public:
  vector<int> partitionLabels(string s) {
    int n = s.size();

    int arr[26];
    for (int i = 0; i < n; ++i)
      arr[s[i] - 'a'] = i;

    vector<int> res;
    int i = 0, j = 0, lastPos = 0;
    for (; j < n; ++j) {
      lastPos = max(lastPos, arr[s[j] - 'a']);
      if (j == lastPos) {
        res.push_back(j - i + 1);
        i = j + 1;
      }
    }

    return res;
  }
};