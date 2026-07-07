class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) return 0;

    std::unordered_set<int> all;
    all.reserve(nums.size());
    for (const auto n : nums) {
      all.insert(n);
    }
    int res{0};
    for (const auto n : all) {
      if (all.contains(n - 1)) continue;
      res = std::max(count_consecutive(n, all), res);
    }
    return res;
  }

 private:
  static int count_consecutive(int start, const std::unordered_set<int>& all) {
    int count{0};
    while (all.contains(start)) {
      ++count;
      if (start == std::numeric_limits<int>::max()) break;
      ++start;
    }
    return count;
  }
};