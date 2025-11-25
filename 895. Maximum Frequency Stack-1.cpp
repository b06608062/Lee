struct Node {
  int val, freq, time;
};

struct NodeCmp {
  bool operator()(const Node &a, const Node &b) const {
    if (a.freq != b.freq)
      return a.freq < b.freq;
    return a.time < b.time;
  }
};

class FreqStack {
public:
  int time;
  unordered_map<int, int> umap; // val, freq
  priority_queue<Node, vector<Node>, NodeCmp> pq;
  FreqStack() : time(0) {}

  void push(int val) {
    umap[val]++;
    pq.push({val, umap[val], ++time});
  }

  int pop() {
    auto node = pq.top();
    pq.pop();
    umap[node.val]--;
    if (umap[node.val] == 0)
      umap.erase(node.val);
    return node.val;
  }
};