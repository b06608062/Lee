// mark
// 實作 HashSet

struct Node {
  int key;
  Node *nxt;
  Node(int key) : key(key), nxt(nullptr) {}
};

class MyHashSet {
public:
  static constexpr int sz = 1000;
  Node *buckets[sz];
  MyHashSet() : buckets{} {}

  void add(int key) {
    int idx = key % sz;
    Node *head = buckets[idx];
    Node *cur = head;
    while (cur) {
      if (cur->key == key)
        return;
      cur = cur->nxt;
    }
    Node *node = new Node(key);
    node->nxt = head;
    buckets[idx] = node;
  }

  void remove(int key) {
    // int idx = key % sz;
    // Node *pre = nullptr, *cur = buckets[idx];
    // while (cur) {
    //   if (cur->key == key) {
    //     if (!pre)
    //       buckets[idx] = cur->nxt;
    //     else
    //       pre->nxt = cur->nxt;
    //     delete cur;
    //     return;
    //   }
    //   pre = cur;
    //   cur = cur->nxt;
    // }
    Node **pp = &buckets[key % sz];
    while (*pp) {
      if ((*pp)->key == key) {
        Node *del = *pp;
        *pp = (*pp)->nxt;
        delete del;
        return;
      }
      pp = &((*pp)->nxt);
    }
  }

  bool contains(int key) {
    int idx = key % sz;
    Node *cur = buckets[idx];
    while (cur) {
      if (cur->key == key)
        return true;
      cur = cur->nxt;
    }
    return false;
  }
};