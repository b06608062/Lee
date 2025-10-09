class Twitter {
public:
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

    // min heap
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> pq;

    for (auto f : follow) {
      auto &tweet = tweets[f];
      for (int i = tweet.size() - 1; i >= max((int)tweet.size() - 10, 0); --i) {
        auto [tid, ts] = tweet[i];
        pq.push({ts, tid});
        if (pq.size() > 10)
          pq.pop();
      }
    }

    int size = pq.size();
    vector<int> res(size);
    while (size--) {
      res[size] = pq.top().second;
      pq.pop();
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