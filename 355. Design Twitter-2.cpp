class Twitter {
public:
  struct Node {
    int ts, tid, uid, idx;
  };
  unordered_map<int, unordered_set<int>> follower;
  unordered_map<int, vector<pair<int, int>>> tweets;
  int timestamp = 0;
  Twitter() {}

  void postTweet(int userId, int tweetId) {
    tweets[userId].push_back({tweetId, timestamp++});
  }

  vector<int> getNewsFeed(int userId) {
    unordered_set<int> follow = follower[userId];
    follow.insert(userId);

    // max heap
    auto comp = [](auto &a, auto &b) { return a.ts < b.ts; };
    priority_queue<Node, vector<Node>, decltype(comp)> pq(comp);

    for (auto f : follow) {
      auto &tweet = tweets[f];
      if (!tweet.empty()) {
        int n = tweet.size();
        pq.push({tweet[n - 1].second, tweet[n - 1].first, f, n - 1});
      }
    }

    vector<int> res;
    while (!pq.empty() && res.size() < 10) {
      auto [ts, tid, uid, idx] = pq.top();
      pq.pop();
      res.push_back(tid);
      if (idx > 0) {
        auto next = tweets[uid][idx - 1];
        pq.push({next.second, next.first, uid, idx - 1});
      }
    }

    return res;
  }

  void follow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    follower[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    if (follower[followerId].count(followeeId))
      follower[followerId].erase(followeeId);
  }
};