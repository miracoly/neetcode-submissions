class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> res(temp.size());
        vector<int> past;
        past.reserve(temp.size());
        const auto n = static_cast<int>(temp.size());
        for (int i = 0; i < n; ++i) {
            while (!past.empty() &&
                   temp[static_cast<size_t>(past.back())] < temp[static_cast<size_t>(i)]) {
                res[static_cast<size_t>(past.back())] = i - past.back();
                past.pop_back();
            }
            past.push_back(i);
        }
        return res;
    }
};
