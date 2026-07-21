class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        const auto n = static_cast<int>(heights.size());
        vector<int> buf;
        buf.reserve(heights.size() + 1);
        stack<int, vector<int>> pending_bars{std::move(buf)};
        int max_area{};

        const auto at = [&heights](int idx) { return heights[static_cast<std::size_t>(idx)]; };

        for (int i{}; i <= n; ++i) {
            const auto h_cur = i < n ? at(i) : 0;

            while (!pending_bars.empty() && at(pending_bars.top()) >= h_cur) {
                const int h = at(pending_bars.top());
                pending_bars.pop();
                const int left = pending_bars.empty() ? -1 : pending_bars.top();
                const int w = i - left - 1;
                max_area = std::max(max_area, w * h);
            }
            pending_bars.push(i);
        }

        return max_area;
    }
};
