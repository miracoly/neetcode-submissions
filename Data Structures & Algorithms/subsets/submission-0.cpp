class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums);
private:
    void backtrack(int i, const std::vector<int>& nums, std::vector<int>& curr,
                 std::vector<std::vector<int>>& res);
};

std::vector<std::vector<int>> Solution::subsets(std::vector<int>& nums) {
  std::vector<int> curr{};
  std::vector<std::vector<int>> res{};
  backtrack(0, nums, curr, res);
  return res;
}

void Solution::backtrack(int i, const std::vector<int>& nums,
                         std::vector<int>& curr,
                         std::vector<std::vector<int>>& res) {

  if (i == static_cast<int>(nums.size())) {
    res.push_back(curr);
    return;
  }

  curr.push_back(nums[static_cast<std::size_t>(i)]);
  backtrack(i + 1, nums, curr, res);

  curr.pop_back();
  backtrack(i + 1, nums, curr, res);
}
