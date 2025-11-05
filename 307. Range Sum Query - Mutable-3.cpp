// Sqrt Decomposition / 分塊
class NumArray {
public:
  int n;
  int B;
  int numBlocks;
  vector<int> nums;
  vector<int> blockSum;

  NumArray(vector<int> &nums) {
    n = nums.size();

    this->nums = nums;
    B = max(1, (int)sqrt(n));
    numBlocks = (n + B - 1) / B;
    blockSum.assign(numBlocks, 0);

    for (int i = 0; i < n; ++i)
      blockSum[i / B] += nums[i];
  }

  void update(int index, int val) {
    int b = index / B;
    int diff = val - nums[index];
    nums[index] = val;
    blockSum[b] += diff;
  }

  int sumRange(int left, int right) {
    int res = 0;
    int bl = left / B;
    int br = right / B;

    if (bl == br) {
      for (int i = left; i <= right; ++i)
        res += nums[i];
      return res;
    }

    int endLeft = (bl + 1) * B - 1;
    for (int i = left; i <= endLeft; ++i)
      res += nums[i];

    for (int b = bl + 1; b <= br - 1; ++b)
      res += blockSum[b];

    int startRight = br * B;
    for (int i = startRight; i <= right; ++i)
      res += nums[i];

    return res;
  }
};
