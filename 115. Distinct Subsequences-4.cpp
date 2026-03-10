class Solution {
public:
  int numDistinct(string s, string t) {
    int m = s.size(), n = t.size();
    vector<unsigned int> f(n + 1, 0);
    f[0] = 1;
    unordered_map<char, vector<int>> umap;
    for (int j = n - 1; j >= 0; --j)
      umap[t[j]].push_back(j + 1);

    for (char &ch : s)
      for (int j : umap[ch])
        f[j] += f[j - 1];

    return f[n];
  }
};