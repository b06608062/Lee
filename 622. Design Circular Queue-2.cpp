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
