class MyHashSet {
public:
  vector<int> data;
  MyHashSet() { data = vector<int>(1000001, 0); }

  void add(int key) { data[key] = 1; }

  void remove(int key) { data[key] = 0; }

  bool contains(int key) { return data[key] == 1; }
};