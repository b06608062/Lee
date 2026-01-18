class AuctionSystem {
public:
  // itemId -> userId -> bidAmount
  unordered_map<int, unordered_map<int, int>> umap1;
  // itemId -> {bidAmount, userId}
  unordered_map<int, set<pair<int, int>>> umap2;
  AuctionSystem() {}

  void addBid(int userId, int itemId, int bidAmount) {
    if (umap1[itemId].count(userId)) {
      umap2[itemId].erase({umap1[itemId][userId], userId});
    }
    umap1[itemId][userId] = bidAmount;
    umap2[itemId].insert({umap1[itemId][userId], userId});
  }

  void updateBid(int userId, int itemId, int newAmount) {
    umap2[itemId].erase({umap1[itemId][userId], userId});
    umap1[itemId][userId] = newAmount;
    umap2[itemId].insert({umap1[itemId][userId], userId});
  }

  void removeBid(int userId, int itemId) {
    umap2[itemId].erase({umap1[itemId][userId], userId});
    umap1[itemId].erase(userId);
  }

  int getHighestBidder(int itemId) {
    if (umap2[itemId].size() > 0)
      return (*umap2[itemId].rbegin()).second;
    return -1;
  }
};