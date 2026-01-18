// mark
// ???
// lazy heap

class AuctionSystem {
public:
  // itemId -> userId -> bidAmount
  unordered_map<int, unordered_map<int, int>> umap1;
  unordered_map<int, priority_queue<pair<int, int>>> umap2;
  AuctionSystem() {}

  void addBid(int userId, int itemId, int bidAmount) {
    umap1[itemId][userId] = bidAmount;
    umap2[itemId].push({bidAmount, userId});
  }

  void updateBid(int userId, int itemId, int newAmount) {
    umap1[itemId][userId] = newAmount;
    umap2[itemId].push({newAmount, userId});
  }

  void removeBid(int userId, int itemId) { umap1[itemId].erase(userId); }

  int getHighestBidder(int itemId) {
    int res = -1;
    auto &pq = umap2[itemId];
    while (pq.size() > 0) {
      auto [bidAmount, userId] = pq.top();
      if (umap1[itemId].count(userId) && umap1[itemId][userId] == bidAmount) {
        res = userId;
        break;
      }
      pq.pop();
    }
    return res;
  }
};