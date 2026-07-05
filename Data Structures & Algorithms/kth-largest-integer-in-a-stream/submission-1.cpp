#include <queue>

class KthLargest {
 public:
  KthLargest(int k, std::vector<int>& nums);

  int add(int val);

 private:
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
  const int k;
};

KthLargest::KthLargest(int k, std::vector<int>& nums) : k(k) {
  for (auto n : nums) {
    if (static_cast<int>(minHeap.size()) < k) {
      minHeap.push(n);
    } else {
      if (n > minHeap.top()) {
        minHeap.pop();
        minHeap.push(n);
      }
    }
  }
}

int KthLargest::add(int val) {
  if (static_cast<int>(minHeap.size()) < k) {
    minHeap.push(val);
  } else if (val > minHeap.top()) {
    minHeap.pop();
    minHeap.push(val);
  }
  return minHeap.top();
}
