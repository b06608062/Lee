class Solution {
public:
  vector<long long> findXSum(vector<int> &nums, int k, int x) {
    int n = nums.size();

    using P = pair<int, int>;
    set<P> setL, setR;
    unordered_map<int, int> umap;

    vector<long long> res;
    long long sumL = 0;

    auto add = [&](int x) {
      P p = {umap[x], x};
      if (p.first == 0)
        return;
      if (!setL.empty() && p > *setL.begin()) {
        setL.insert(p);
        sumL += 1LL * p.first * p.second;
      } else
        setR.insert(p);
    };

    auto del = [&](int x) {
      P p = {umap[x], x};
      if (p.first == 0)
        return;
      auto it = setL.find(p);
      if (it != setL.end()) {
        setL.erase(it);
        sumL -= 1LL * p.first * p.second;
      } else
        setR.erase(p);
    };

    for (int i = 0; i < n; ++i) {
      int toAdd = nums[i];
      del(toAdd);
      umap[toAdd]++;
      add(toAdd);
      if (i < k - 1)
        continue;
      if (setL.size() > x) {
        auto p = *setL.begin();
        setL.erase(p);
        sumL -= 1LL * p.first * p.second;
        setR.insert(p);
      }
      while (!setR.empty() && setL.size() < x) {
        auto p = *setR.rbegin();
        setR.erase(p);
        setL.insert(p);
        sumL += 1LL * p.first * p.second;
      }

      res.push_back(sumL);

      int toRemove = nums[i - k + 1];
      del(toRemove);
      umap[toRemove]--;
      add(toRemove);
    }

    return res;
  }
};