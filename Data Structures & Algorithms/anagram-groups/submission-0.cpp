class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> grouped;
        for (const auto& s : strs) {
            auto sorted = s;
            sort(sorted.begin(), sorted.end());
            grouped[sorted].push_back(s);
        }
        vector<vector<string>> res;
        res.reserve(grouped.size());
        for (const auto& [_, val] : grouped) {
            res.push_back(std::move(val));
        }
        return res;
    }
};
