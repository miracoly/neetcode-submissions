class Solution {
   public:
    bool isPalindrome(string s) {
        int l{0};
        int r{static_cast<int>(s.size()) - 1};
        while (l < r) {
            const auto lc = static_cast<unsigned char>(s[static_cast<size_t>(l)]);
            const auto rc = static_cast<unsigned char>(s[static_cast<size_t>(r)]);
            if (!std::isalnum(lc)) {
                ++l;
                continue;
            }
            if (!std::isalnum(rc)) {
                --r;
                continue;
            }
            if (std::tolower(lc) != std::tolower(rc)) return false;
            ++l;
            --r;
        }
        return true;
    }
};
