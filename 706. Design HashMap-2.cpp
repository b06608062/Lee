struct Node {
  int key, val;
  Node *nxt;
  Node(int key, int val) : key(key), val(val), nxt(nullptr) {}
};

class MyHashMap {
public:
  static constexpr int sz = 1000;
  Node *buckets[sz];
  MyHashMap() : buckets{} {}

  void put(int key, int value) {
    int idx = key % sz;
    Node *head = buckets[idx];
    Node *cur = head;
    while (cur) {
      if (cur->key == key) {
        cur->val = value;
        return;
      }
      cur = cur->nxt;
    }
    Node *node = new Node(key, value);
    node->nxt = head;
    buckets[idx] = node;
  }

  int get(int key) {
    int idx = key % sz;
    Node *cur = buckets[idx];
    while (cur) {
      if (cur->key == key)
        return cur->val;
      cur = cur->nxt;
    }
    return -1;
  }

  void remove(int key) {
    int idx = key % sz;
    Node *pre = nullptr, *cur = buckets[idx];
    while (cur) {
      if (cur->key == key) {
        if (!pre)
          buckets[idx] = cur->nxt;
        else
          pre->nxt = cur->nxt;
        delete cur;
        return;
      }
      pre = cur;
      cur = cur->nxt;
    }
    // Node **pp = &buckets[key % sz];
    // while (*pp) {
    //   if ((*pp)->key == key) {
    //     Node *del = *pp;
    //     *pp = (*pp)->nxt;
    //     delete del;
    //     return;
    //   }
    //   pp = &((*pp)->nxt);
    // }
  }
};
