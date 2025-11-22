struct Node {
  int key, val, freq, time;
  Node(int k, int v, int t) : key(k), val(v), freq(1), time(t) {}
};

struct NodeCmp {
  bool operator()(const Node *a, const Node *b) const {
    if (a->freq != b->freq)
      return a->freq < b->freq;
    return a->time < b->time;
  }
};

class LFUCache {
public:
  LFUCache(int capacity) : capacity(capacity), time(0) {}

  int get(int key) {
    if (!umap.count(key))
      return -1;
    Node *node = umap[key];
    touch(node);
    return node->val;
  }

  void put(int key, int value) {
    if (capacity == 0)
      return;
    if (umap.count(key)) {
      Node *node = umap[key];
      node->val = value;
      touch(node);
      return;
    } else {
      if (umap.size() >= capacity) {
        Node *node = *cache.begin();
        umap.erase(node->key);
        cache.erase(node);
        delete node;
      }
      Node *newNode = new Node(key, value, ++time);
      umap[key] = newNode;
      cache.insert(newNode);
    }
  }

private:
  set<Node *, NodeCmp> cache;
  unordered_map<int, Node *> umap;
  int capacity, time;
  void touch(Node *node) {
    cache.erase(node);
    node->freq++;
    node->time = ++time;
    cache.insert(node);
  }
};