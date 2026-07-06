class Solution {
public:
    string encode(vector<string>& strs);
    vector<string> decode(string s);
};

std::string Solution::encode(std::vector<std::string>& strs) {
  std::string res;
  for (const auto& s : strs) {
    res.push_back(static_cast<char>(s.size()));
    res += s;
  }
  return res;
}

std::vector<std::string> Solution::decode(std::string s) {
  std::vector<std::string> res;
  std::size_t cursor{0};
  while (cursor < s.size()) {
    const auto len =
        static_cast<std::size_t>(static_cast<unsigned char>(s[cursor++]));
    res.push_back(s.substr(cursor, len));
    cursor += len;
  }
  return res;
}
