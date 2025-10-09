struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MyCircularQueue {
public:
  ListNode *head, *tail;
  int size, capacity;

  MyCircularQueue(int k) {
    head = tail = nullptr;
    size = 0, capacity = k;
  }

  bool enQueue(int value) {
    if (size == capacity)
      return false;

    ListNode *node = new ListNode(value);
    if (size == 0)
      head = tail = node;
    else {
      tail->next = node;
      tail = node;
    }
    size++;

    return true;
  }

  bool deQueue() {
    if (size == 0)
      return false;

    ListNode *node = head;
    head = head->next;
    delete node;
    size--;

    return true;
  }

  int Front() {
    if (size == 0)
      return -1;

    return head->val;
  }

  int Rear() {
    if (size == 0)
      return -1;

    return tail->val;
  }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == capacity; }
};