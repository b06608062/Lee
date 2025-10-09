struct Node {
  int key;
  int val;
  Node *next;
  Node(int k, int v) : key(k), val(v), next(nullptr) {}
};

class MyHashMap {
public:
  static constexpr int size = 1000; // 類別共享，且是編譯期常數
  Node *myMap[size];
  MyHashMap() : myMap{} {}

  void put(int key, int value) {
    int idx = key % size;

    Node *head = myMap[idx];
    Node *cur = head;
    while (cur) {
      if (cur->key == key) {
        cur->val = value;
        return;
      }
      cur = cur->next;
    }

    Node *node = new Node(key, value);
    node->next = head;
    myMap[idx] = node;
  }

  void remove(int key) {
    // int idx = key % size;

    // Node *prev = nullptr, *cur = myMap[idx];
    // while (cur) {
    //   if (cur->key == key) {
    //     if (!prev)
    //       myMap[idx] = cur->next;
    //     else
    //       prev->next = cur->next;
    //     delete cur;
    //     return;
    //   } else {
    //     prev = cur;
    //     cur = cur->next;
    //   }
    // }

    Node **pp = &myMap[key % size];
    while (*pp) {
      if ((*pp)->key == key) {
        Node *del = *pp;
        *pp = (*pp)->next;
        delete del;
        return;
      }
      pp = &((*pp)->next);
    }
  }

  int get(int key) {
    int idx = key % size;

    Node *cur = myMap[idx];
    while (cur) {
      if (cur->key == key)
        return cur->val;
      cur = cur->next;
    }

    return -1;
  }
};