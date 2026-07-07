#include <utility>

class Solution {
   public:
    bool isValid(string s) {
        std::stack<char, std::vector<char>> stack;
        for (const char c : s) {
            if (stack.empty() && !is_open(c)) return false;
            if (is_open(c)) {
                stack.push(c);
                continue;
            }
            if (get_closing(stack.top()) == c) {
                stack.pop();
                continue;
            }
            return false;
        }
        return stack.empty();
    }

   private:
    static constexpr bool is_open(char c) { return c == '(' || c == '[' || c == '{'; }
    static constexpr char get_closing(char c) {
        switch (c) {
            case '(':
                return ')';
            case '[':
                return ']';
            case '{':
                return '}';
        }
        std::unreachable();
    }
};
