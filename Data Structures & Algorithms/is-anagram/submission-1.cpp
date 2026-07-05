class Solution {
   public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        size_t l{0};
        size_t r{t.size() - 1};

        std::array<int, 'z' + 1> ss{};
        std::array<int, 'z' + 1> ts{};

        while (l < s.size()) {
            ss[s[l++]]++;
            ts[t[r--]]++;
        }
        
        for (size_t i = 'a'; i <= 'z'; ++i) {
            if (ss[i] != ts[i]) return false;
        }
        return true;
    }
};
