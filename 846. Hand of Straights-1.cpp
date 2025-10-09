class Solution {
public:
  bool isNStraightHand(vector<int> &hand, int groupSize) {
    int n = hand.size();
    if (n % groupSize)
      return false;

    unordered_map<int, int> umap;
    for (auto x : hand)
      umap[x]++;

    vector<int> arr;
    for (auto [x, _] : umap)
      arr.push_back(x);

    sort(arr.begin(), arr.end());

    for (auto x : arr)
      if (umap[x] > 0) {
        int count = umap[x];
        for (int i = x; i < x + groupSize; ++i) {
          umap[i] -= count;
          if (umap[i] < 0)
            return false;
        }
      }

    return true;
  }
};