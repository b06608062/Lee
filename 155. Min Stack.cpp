class MinStack {
public:
  stack<int> dataStack;
  stack<int> minStack;
  MinStack() {}

  void push(int val) {
    dataStack.push(val);
    if (minStack.empty() || val <= minStack.top())
      minStack.push(val);
  }

  void pop() {
    if (!dataStack.empty()) {
      if (dataStack.top() == minStack.top())
        minStack.pop();
      dataStack.pop();
    }
  }

  int top() { return dataStack.top(); }

  int getMin() { return minStack.top(); }
};