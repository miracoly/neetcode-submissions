class Solution {
public:
    static int lastStoneWeight(const std::vector<int>& stones);
};

int Solution::lastStoneWeight(const std::vector<int>& stones) {
  if (stones.empty()) return 0;
  if (stones.size() == 1) return stones[0];

  std::priority_queue maxHeap(stones.begin(), stones.end());
  while (maxHeap.size() > 1) {
    const int maxFst = maxHeap.top();
    maxHeap.pop();
    const int maxSnd = maxHeap.top();
    maxHeap.pop();
    const int diff = std::abs(maxFst - maxSnd);
    maxHeap.push(diff);
  }

  return maxHeap.top();
}