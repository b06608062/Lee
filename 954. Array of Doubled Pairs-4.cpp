class Solution {
public:
  bool canReorderDoubled(vector<int> &arr) {
    vector<int> positive, negative;
    for (auto x : arr)
      if (x >= 0)
        positive.push_back(x);
      else
        negative.push_back(-x);

    sort(positive.begin(), positive.end());
    sort(negative.begin(), negative.end());

    return checkValidArray(positive) && checkValidArray(negative);
  }

  bool checkValidArray(vector<int> &arr) {
    unordered_map<int, int> umap;

    for (auto x : arr)
      if (x % 2 == 0 && umap.count(x / 2)) {
        umap[x / 2]--;
        if (umap[x / 2] == 0)
          umap.erase(x / 2);
      } else
        umap[x]++;

    return umap.empty();
  }
};