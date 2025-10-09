template <class T1, class T2> struct PairHash {
  size_t operator()(const pair<T1, T2> &p) const noexcept {
    size_t h1 = hash<T1>{}(p.first);
    size_t h2 = hash<T2>{}(p.second);
    size_t h = h1;
    h ^= h2 + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2);
    return h;
  }
};

class DetectSquares {
public:
  unordered_map<pair<int, int>, int, PairHash<int, int>> umap;
  DetectSquares() {}

  void add(vector<int> point) { umap[{point[0], point[1]}]++; }

  int count(vector<int> point) {
    int x1 = point[0], y1 = point[1], res = 0;
    for (auto &[p2, cnt] : umap) {
      auto [x2, y2] = p2;
      if (x1 == x2 || y1 == y2 || abs(x1 - x2) != abs(y1 - y2))
        continue;
      auto it1 = umap.find({x1, y2});
      auto it2 = umap.find({x2, y1});
      if (it1 != umap.end() && it2 != umap.end())
        res += cnt * it1->second * it2->second;
    }

    return res;
  }
};