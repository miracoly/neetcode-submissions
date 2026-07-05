class Solution {
public:
int search(vector<int> &nums, int target) {
  int l{0};
  int r{static_cast<int>(nums.size()) - 1};

  while (l <= r) {
    int m = (r + l) / 2;

    if (nums[static_cast<size_t>(m)] < target) {
      l = m + 1;
    } else if (nums[static_cast<size_t>(m)] > target) {
      r = m - 1;
    } else {
      return m;
    }
  }
  return -1;
}

};
