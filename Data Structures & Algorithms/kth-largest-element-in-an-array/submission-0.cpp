class Solution {
public:
    int findKthLargest(const vector<int>& nums, int k);
};

int Solution::findKthLargest(const std::vector<int>& nums, int k) {
  std::priority_queue maxHeap(nums.begin(), nums.end());

  while (--k > 0) {
    maxHeap.pop();
  }

  return maxHeap.top();
}
