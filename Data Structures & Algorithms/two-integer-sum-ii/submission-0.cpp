class Solution {
   public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l{0};
        int r{static_cast<int>(numbers.size()) - 1};

        const auto at = [&numbers](int idx) { return numbers[static_cast<std::size_t>(idx)]; };
        const auto sum = [&at, &l, &r]() { return at(l) + at(r); };

        while (sum() != target) {
            if (sum() > target) {
                --r;
            } else {
                ++l;
            }
        }

        return vector<int>{l + 1, r + 1};
    }
};
