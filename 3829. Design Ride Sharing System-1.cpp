class RideSharingSystem {
public:
  queue<int> q1, q2;
  unordered_set<int> in;
  RideSharingSystem() {}

  void addRider(int riderId) {
    q1.push(riderId);
    in.insert(riderId);
  }

  void addDriver(int driverId) { q2.push(driverId); }

  vector<int> matchDriverWithRider() {
    while (!q1.empty() && !in.count(q1.front())) {
      q1.pop();
    }
    if (!q1.empty() && !q2.empty()) {
      int rid = q1.front(), did = q2.front();
      q1.pop(), q2.pop();
      return {did, rid};
    }
    return {-1, -1};
  }

  void cancelRider(int riderId) {
    if (in.count(riderId)) {
      in.erase(riderId);
    }
  }
};
