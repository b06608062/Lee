struct Node {
  int key, value;
  Node *prev;
  Node *next;
  Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
  int capacity;
  unordered_map<int, Node *> umap;
  Node *head, *tail;

  void remove(Node *node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
  }

  void addHead(Node *node) {
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
  }

public:
  LRUCache(int capacity) : capacity(capacity) {
    head = new Node(0, 0);
    tail = new Node(0, 0);
    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (!umap.count(key))
      return -1;

    Node *node = umap[key];
    remove(node);
    addHead(node);

    return node->value;
  }

  void put(int key, int value) {
    if (umap.count(key)) {
      Node *node = umap[key];
      node->value = value;
      remove(node);
      addHead(node);
    } else {
      if (umap.size() >= capacity) {
        Node *lru = tail->prev;
        remove(lru);
        umap.erase(lru->key);
        delete lru;
      }
      Node *node = new Node(key, value);
      addHead(node);
      umap[key] = node;
    }
  }

  ~LRUCache() {
    Node *cur = head;
    while (cur != nullptr) {
      Node *next = cur->next;
      delete cur;
      cur = next;
    }
  }
};
