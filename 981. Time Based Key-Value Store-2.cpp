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

    // 尋找第一個 pair.first > timestamp 的位置（STL 這個重載會呼叫 comp(value,
    // element)） 情況總結（假設 arr 已按 pair.first 遞增）：
    // - arr 為空：              it == arr.begin() == arr.end()
    // - timestamp < arr[0].first： it == arr.begin()         （插在最前）
    // - 存在等於 timestamp 的元素：it 指向「該元素(們)之後」的位置
    // - arr[i-1].first <= timestamp < arr[i].first： it == arr.begin() + i
    // - timestamp >= arr.back().first： it == arr.end()      （插在最後）
    auto it = upper_bound(arr.begin(), arr.end(), timestamp,
                          [](int t, auto &p) { return t < p.first; });

    return it == arr.begin() ? "" : prev(it)->second;
  }
};