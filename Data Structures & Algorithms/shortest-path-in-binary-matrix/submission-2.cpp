#include <array>
#include <cstddef>
#include <queue>
#include <utility>
#include <vector>

class Solution {
public:
    int shortestPathBinaryMatrix(const vector<vector<int>>& grid);
};

namespace {

constexpr std::array<std::pair<int, int>, 8> neighbors{{
    // clang-format off
    {-1, -1},{-1, 0}, {-1, 1},
    {0, -1},          {0, 1},
    {1, -1}, {1, 0}, {1, 1}  // clang-format on
}};

}  // namespace

int Solution::shortestPathBinaryMatrix(
    const std::vector<std::vector<int>>& grid) {
  const auto invalidGrid = [&]() -> bool {
    return grid.empty() || grid[0].empty() || grid[0][0] == 1 ||
           grid[grid.size() - 1][grid[0].size() - 1] == 1;
  };
  if (invalidGrid()) return -1;

  const auto rows = static_cast<int>(grid.size());
  const auto cols = static_cast<int>(grid[0].size());
  const auto inBounds = [&rows, &cols](int x, int y) -> bool {
    return x >= 0 && x < rows && y >= 0 && y < cols;
  };

  int length{1};
  std::queue<std::pair<int, int>> queue{};
  std::vector<std::vector<bool>> visited(
      grid.size(), std::vector<bool>(grid[0].size(), false));
  queue.emplace(0, 0);
  visited[0][0] = true;

  while (!queue.empty()) {
    const auto levelSize = static_cast<int>(queue.size());
    for (int i = 0; i < levelSize; ++i) {
      const auto [r, c] = queue.front();
      queue.pop();

      if (r == rows - 1 && c == cols - 1) return length;

      for (const auto& n : neighbors) {
        const auto [deltaR, deltaC] = n;
        const auto newR = r + deltaR;
        const auto newC = c + deltaC;

        if (!inBounds(newR, newC)) continue;
        const auto uR = static_cast<std::size_t>(newR);
        const auto uC = static_cast<std::size_t>(newC);
        if (grid[uR][uC] == 1) continue;
        if (visited[uR][uC]) continue;

        queue.emplace(newR, newC);
        visited[uR][uC] = true;
      }
    };
    length++;
  }

  return -1;
}
