class CustomStack {
public:
  vector<int> st;
  unordered_map<int, int> umap;
  int msz;
  CustomStack(int maxSize) : msz(maxSize) {}

  void push(int x) {
    if (st.size() < msz)
      st.push_back(x);
  }

  int pop() {
    int sz = st.size();
    if (sz == 0)
      return -1;
    int x = st[sz - 1];
    st.pop_back();
    int inc = umap[sz - 1];
    umap[sz - 1] = 0;
    if (sz - 2 >= 0)
      umap[sz - 2] += inc;
    return x + inc;
  }

  void increment(int k, int val) {
    int sz = st.size();
    umap[min(k - 1, sz - 1)] += val;
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */