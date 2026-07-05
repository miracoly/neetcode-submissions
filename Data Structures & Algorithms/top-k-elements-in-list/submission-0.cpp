struct Count {
    int num;
    int count;
};

struct Comp {
    bool operator()(const Count& a, const Count& b) const { return a.count < b.count; }
};

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (const auto n : nums) {
            counts[n]++;
        }

        priority_queue<Count, vector<Count>, Comp> heap;
        for (const auto [num, count] : counts) {
            heap.push(Count{.num = num, .count = count});
        }

        vector<int> res;
        res.reserve(static_cast<size_t>(k));
        while (k--) {
            res.push_back(heap.top().num);
            heap.pop();
        }

        return res;
    }
};
