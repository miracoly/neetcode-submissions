class Solution {
   public:
    int rob(vector<int>& nums) {
        unordered_map<int, int> cache;
        return rob(static_cast<int>(nums.size() - 1), cache, nums);
    }

   private:
    int rob(int i, unordered_map<int, int>& cache, const vector<int>& nums) {
        if (i < 0) return 0;
        if (const auto it = cache.find(i); it != cache.end()) {
            return it->second;
        };
        const std::size_t ui = static_cast<std::size_t>(i);
        const int res = std::max(nums[ui] + rob(i - 2, cache, nums), rob(i - 1, cache, nums));
        cache[i] = res;
        return res;
    }
};
