struct Node {
  int key, val, freq;
  list<Node *>::iterator it;
  Node(int k, int v) : key(k), val(v), freq(1) {}
};

class LFUCache {
public:
  LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

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
    }

    if (umap.size() >= capacity) {
      auto &lst = freqList[minFreq];
      Node *old = lst.back();
      lst.pop_back();
      if (lst.empty())
        freqList.erase(minFreq);
      umap.erase(old->key);
      delete old;
    }

    Node *node = new Node(key, value);
    minFreq = 1;
    auto &lst = freqList[1];
    lst.push_front(node);
    node->it = lst.begin();
    umap[key] = node;
  }

private:
  int capacity, minFreq;
  unordered_map<int, Node *> umap;
  unordered_map<int, list<Node *>> freqList;
  void touch(Node *node) {
    int f = node->freq;
    auto &lst = freqList[f];
    lst.erase(node->it);
    if (lst.empty()) {
      freqList.erase(f);
      if (minFreq == f)
        ++minFreq;
    }
    ++node->freq;
    auto &newList = freqList[node->freq];
    newList.push_front(node);
    node->it = newList.begin();
  }
};
