class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unsigned> rows(9);
        vector<unsigned> columns(9);
        vector<unsigned> boxes(9);
        for (unsigned r = 0; r < board.size(); ++r) {
            for (unsigned c = 0; c < board.size(); ++c) {
                if (!isdigit(static_cast<unsigned char>(board[r][c]))) continue;

                const unsigned bitmask = 1u << static_cast<unsigned>(board[r][c] - '0');
                const std::size_t b = (r / 3) * 3 + (c / 3);
                if (rows[r] & bitmask || columns[c] & bitmask || boxes[b] & bitmask) return false;
                rows[r] |= bitmask;
                columns[c] |= bitmask;
                boxes[b] |= bitmask;
            }
        }
        return true;
    }
};
