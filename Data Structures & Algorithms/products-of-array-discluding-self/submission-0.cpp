class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<long long> left(nums.size());
        vector<long long> right(nums.size());
        std::exclusive_scan(nums.begin(), nums.end(), left.begin(), 1ll,
                            std::multiplies<long long>{});
        std::exclusive_scan(nums.rbegin(), nums.rend(), right.rbegin(), 1ll,
                            std::multiplies<long long>{});

        const int len = static_cast<int>(nums.size());
        for (int i = 0; i < len; ++i) {
            const auto ui = static_cast<size_t>(i);
            nums[ui] = static_cast<int>(left[ui] * right[ui]);
        }
        return nums;
    }
};
