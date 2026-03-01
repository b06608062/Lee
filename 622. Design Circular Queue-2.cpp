class MyCircularQueue {
public:
  vector<int> data;
  int size, capacity;
  int front, rear;
  MyCircularQueue(int k) : data(k), size(0), capacity(k), front(0), rear(0) {}

  bool enQueue(int value) {
    if (isFull())
      return false;

    data[rear] = value;
    rear = (rear + 1) % capacity;
    size++;

    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;

    front = (front + 1) % capacity;
    size--;

    return true;
  }

  int Front() {
    if (isEmpty())
      return -1;

    return data[front];
  }

  int Rear() {
    if (isEmpty())
      return -1;

    return data[(rear - 1 + capacity) % capacity];
  }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == capacity; }
};

class MyCircularQueue {
private:
  vector<int> data;
  int head, tail;

public:
  MyCircularQueue(int k) : data(k + 1), head(0), tail(0) {}

  bool enQueue(int value) {
    if (isFull())
      return false;
    data[tail] = value;
    tail = (tail + 1) % data.size();
    return true;
  }

  bool deQueue() {
    if (isEmpty())
      return false;
    head = (head + 1) % data.size();
    return true;
  }

  int Front() {
    if (isEmpty())
      return -1;
    return data[head];
  }

  int Rear() {
    if (isEmpty())
      return -1;
    return data[(tail - 1 + data.size()) % data.size()];
  }

  bool isEmpty() { return head == tail; }

  bool isFull() { return (tail + 1) % data.size() == head; }
};