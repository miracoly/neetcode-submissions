#include <cstddef>
#include <vector>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
Matrix<T> mkMatrix(std::size_t rows, std::size_t cols, T defaultValue = T()) {
  return Matrix<T>(rows, std::vector<T>(cols, defaultValue));
}

class Solution {
 public:
  static int orangesRotting(Matrix<int>& grid);
};

#include <array>
#include <cstddef>
#include <queue>
#include <utility>

namespace {

constexpr std::array<std::pair<int, int>, 4> neighbors{{
    // clangformat off
    {0, -1},
    {1, 0},
    {0, 1},
    {-1, 0}  // clangformat on
}};

}  // namespace

int Solution::orangesRotting(Matrix<int>& grid) {
  if (grid.empty() || grid[0].empty()) return -1;

  std::queue<std::pair<int, int>> queue;
  int ones{0};
  for (std::size_t r = 0; r < grid.size(); ++r) {
    for (std::size_t c = 0; c < grid[0].size(); ++c) {
      if (grid[r][c] == 2) {
        queue.emplace(r, c);
      } else if (grid[r][c] == 1) {
        ones++;
      }
    }
  }

  if (ones == 0) return 0;

  const auto shouldVisit = [&](int x, int y) -> bool {
    const auto ux = static_cast<std::size_t>(x);
    const auto uy = static_cast<std::size_t>(y);
    return x >= 0 && x < static_cast<int>(grid.size()) && y >= 0 &&
           y < static_cast<int>(grid[0].size()) && grid[ux][uy] == 1;
  };

  int minutes{-1};
  while (!queue.empty()) {
    auto len = static_cast<int>(queue.size());
    while ((len--) > 0) {
      const auto [r, c] = queue.front();
      queue.pop();
      for (const auto& [dr, dc] : neighbors) {
        const auto nr = r + dr;
        const auto nc = c + dc;
        if (shouldVisit(nr, nc)) {
          queue.emplace(nr, nc);
          const auto ur = static_cast<std::size_t>(nr);
          const auto uc = static_cast<std::size_t>(nc);
          grid[ur][uc] = 2;
        }
      }
    }
    minutes++;
  }

  for (std::size_t r = 0; r < grid.size(); ++r) {
    for (std::size_t c = 0; c < grid[0].size(); ++c) {
      if (grid[r][c] == 1) return -1;
    }
  }

  return minutes;
}
