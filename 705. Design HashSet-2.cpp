struct Node {
  int key;
  Node *next;
  Node(int k) : key(k), next(nullptr) {}
};

class MyHashSet {
public:
  static constexpr int size = 1000; // 類別共享，且是編譯期常數
  Node *mySet[size];
  MyHashSet() : mySet{} {}

  void add(int key) {
    int idx = key % size;

    Node *head = mySet[idx];
    Node *cur = head;
    while (cur) {
      if (cur->key == key)
        return;
      cur = cur->next;
    }

    Node *node = new Node(key);
    node->next = head;
    mySet[idx] = node;
  }

  void remove(int key) {
    int idx = key % size;

    Node *prev = nullptr, *cur = mySet[idx];
    while (cur) {
      if (cur->key == key) {
        if (!prev)
          mySet[idx] = cur->next;
        else
          prev->next = cur->next;
        delete cur;
        return;
      } else {
        prev = cur;
        cur = cur->next;
      }
    }

    // Node **pp = &mySet[key % size];
    // while (*pp) {
    //   if ((*pp)->key == key) {
    //     Node *del = *pp;
    //     *pp = (*pp)->next;
    //     delete del;
    //     return;
    //   }
    //   pp = &((*pp)->next);
    // }
  }

  bool contains(int key) {
    int idx = key % size;

    Node *cur = mySet[idx];
    while (cur) {
      if (cur->key == key)
        return true;
      cur = cur->next;
    }

    return false;
  }
};