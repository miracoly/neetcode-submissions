class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> occ = toMap(nums);
    vector<int> res(2, -1);
    for (int i = 0; i < static_cast<int>(nums.size()); i++) {
      int n = target - nums[i];
      auto it = occ.find(n);
      if (it != occ.end() && it->second != i) {
        res[0] = min(i, it->second);
        res[1] = max(i, it->second);
        break;
      }
    }
    return res;
  }

 private:
  unordered_map<int, int> toMap(const vector<int>& nums) {
    unordered_map<int, int> res{};
    int i{0};
    for (int n : nums) {
      res[n] = res.count(n) ? min(res[n], i) : i;
      i++;
    }
    return res;
  }
};