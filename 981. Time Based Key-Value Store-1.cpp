class TimeMap {
  unordered_map<string, vector<pair<int, string>>> umap;

public:
  void set(string key, string value, int timestamp) {
    umap[key].push_back({timestamp, value});
  }

  string get(string key, int timestamp) {
    if (!umap.count(key))
      return "";

    auto &arr = umap[key];
    int l = 0, r = arr.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      if (arr[m].first <= timestamp)
        l = m + 1;
      else
        r = m;
    }

    return l == 0 ? "" : arr[l - 1].second;
  }
};
