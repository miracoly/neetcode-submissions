class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target);
 private:
    void backtrack(int i, int currSum, const int targetSum,
                 const std::vector<int>& nums, std::vector<int>& curr,
                 std::vector<std::vector<int>>& res);

};

std::vector<std::vector<int>> Solution::combinationSum(std::vector<int>& nums,
                                                       int target) {
  std::vector<int> curr{};
  std::vector<std::vector<int>> res{};
  backtrack(0, 0, target, nums, curr, res);
  return res;
}

void Solution::backtrack(int i, int currSum, const int targetSum,
                         const std::vector<int>& nums, std::vector<int>& curr,
                         std::vector<std::vector<int>>& res) {
  if (currSum == targetSum) {
    res.push_back(curr);
    return;
  }

  if (currSum > targetSum || i >= static_cast<int>(nums.size())) {
    return;
  }

  curr.push_back(nums[static_cast<std::size_t>(i)]);
  backtrack(i, currSum + nums[static_cast<std::size_t>(i)], targetSum, nums,
            curr, res);
  curr.pop_back();  // undo

  backtrack(i + 1, currSum, targetSum, nums, curr, res);
}

