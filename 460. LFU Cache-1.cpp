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

struct Node {
  int key, val, freq, time;
  Node(int k, int v, int f, int t) : key(k), val(v), freq(f), time(t) {}
};

struct Comp {
  bool operator()(const Node *a, const Node *b) const {
    if (a->freq != b->freq)
      return a->freq < b->freq;
    return a->time < b->time;
  }
};

class LFUCache {
public:
  unordered_map<int, Node *> umap;
  set<Node *, Comp> cache;
  int cap, time;
  LFUCache(int capacity) {
    cap = capacity;
    time = 0;
  }

  int get(int key) {
    auto it = umap.find(key);
    if (it == umap.end())
      return -1;
    touch(it->second);
    return it->second->val;
  }

  void put(int key, int value) {
    auto it = umap.find(key);
    if (it == umap.end()) {
      if (umap.size() == cap) {
        auto lfu = *cache.begin();
        umap.erase(lfu->key);
        cache.erase(lfu);
        delete lfu;
      }
      Node *new_node = new Node(key, value, 0, ++time);
      umap[key] = new_node;
      cache.insert(new_node);
    } else {
      it->second->val = value;
      touch(it->second);
    }
  }

  void touch(Node *node) {
    cache.erase(node);
    node->freq++;
    node->time = ++time;
    cache.insert(node);
  }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */