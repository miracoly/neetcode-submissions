#include <array>
#include <utility>
#include <vector>

class Solution {
 public:
  static int maxAreaOfIsland(std::vector<std::vector<int>>& grid);

 private:
  static int dfs(int x, int y, const std::vector<std::vector<int>>& grid);
};

namespace {

constexpr std::array<std::pair<int, int>, 4> neighbors{{
    // clangformat off
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}  // clangformat on
}};

}  // namespace

int Solution::maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
  if (grid.empty() || grid[0].empty()) return 0;
  const auto rows = static_cast<int>(grid.size());
  const auto cols = static_cast<int>(grid[0].size());

  int maxArea{0};
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      const auto _r = static_cast<size_t>(r);
      const auto _c = static_cast<size_t>(c);
      if (grid[_r][_c] == 1) {
        maxArea = std::max(maxArea, dfs(r, c, grid));
      }
    }
  }

  return maxArea;
}

int Solution::dfs(int x, int y, const std::vector<std::vector<int>>& grid) {
  const auto inBounds = [&](int x, int y) -> bool {
    return x >= 0 && x < static_cast<int>(grid.size()) && y >= 0 &&
           y < static_cast<int>(grid[0].size());
  };

  int area{0};
  std::vector visited(grid.size(), std::vector<bool>((grid[0].size())));
  std::vector<std::pair<int, int>> stack{};
  stack.emplace_back(x, y);

  while (!stack.empty()) {
    const auto [cx, cy] = stack.back();
    stack.pop_back();

    if (!inBounds(cx, cy)) continue;
    const auto _x = static_cast<size_t>(cx);
    const auto _y = static_cast<size_t>(cy);
    if (grid[_x][_y] == 0 || visited[_x][_y]) continue;

    visited[_x][_y] = true;
    area++;
    for (const auto& n : neighbors) {
      const auto newX = cx + n.first;
      const auto newY = cy + n.second;
      stack.emplace_back(newX, newY);
    }
  }

  return area;
}
