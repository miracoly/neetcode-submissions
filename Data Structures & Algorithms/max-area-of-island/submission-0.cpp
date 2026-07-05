#include <array>

class Solution {
 public:
  int maxAreaOfIsland(std::vector<std::vector<int>>& grid);

 private:
  void dfs(int x, int y, int& area, std::vector<std::vector<bool>>& visited,
           const std::vector<std::vector<int>>& grid);
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

  std::vector visited(grid.size(), std::vector<bool>((grid[0].size())));
  int maxArea{0};
  for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
      const auto _r = static_cast<size_t>(r);
      const auto _c = static_cast<size_t>(c);
      if (grid[_r][_c] == 1 && !visited[_r][_c]) {
        int area{0};
        dfs(r, c, area, visited, grid);
        maxArea = std::max(maxArea, area);
      }
    }
  }

  return maxArea;
}

void Solution::dfs(int x, int y, int& area,
                   std::vector<std::vector<bool>>& visited,
                   const std::vector<std::vector<int>>& grid) {
  const auto inBounds = [&](int x, int y) -> bool {
    return x >= 0 && x < static_cast<int>(grid.size()) && y >= 0 &&
           y < static_cast<int>(grid[0].size());
  };
  if (!inBounds(x, y)) return;
  const auto _x = static_cast<size_t>(x);
  const auto _y = static_cast<size_t>(y);
  if (grid[_x][_y] == 0 || visited[_x][_y]) return;

  visited[_x][_y] = true;
  area++;
  for (const auto& n : neighbors) {
    const auto newX = x + n.first;
    const auto newY = y + n.second;
    dfs(newX, newY, area, visited, grid);
  }
}
