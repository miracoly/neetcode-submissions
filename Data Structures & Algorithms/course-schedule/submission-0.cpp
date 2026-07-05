class Solution {
 public:
  static bool canFinish(int numCourses,
                        const std::vector<std::vector<int>>& prerequisites);
};

namespace grph {

class Graph {
 public:
  Graph(int numCourses, const std::vector<std::vector<int>>& prerequisites);
  bool canFinish() const;

 private:
  int numCourses_;
  std::vector<std::vector<int>> adjList_;

  enum class State : std::int8_t {
    Unvisited,
    InProgress,
    Done,
  };

  bool dfs(int course, std::vector<State>& states) const;
};

}  // namespace grph

bool Solution::canFinish(int numCourses,
                         const std::vector<std::vector<int>>& prerequisites) {
  const grph::Graph graph(numCourses, prerequisites);
  return graph.canFinish();
}

namespace grph {

Graph::Graph(int numCourses, const std::vector<std::vector<int>>& prerequisites)
    : numCourses_(numCourses), adjList_(static_cast<std::size_t>(numCourses)) {
  for (const auto& prq : prerequisites) {
    adjList_[static_cast<std::size_t>(prq[0])].push_back(prq[1]);
  }
}

bool Graph::canFinish() const {
  std::vector<State> states(static_cast<std::size_t>(numCourses_),
                            State::Unvisited);
  for (int i = 0; i < numCourses_; ++i) {
    if (states[static_cast<std::size_t>(i)] == State::Done) continue;
    if (!dfs(i, states)) return false;
  }

  return true;
}

bool Graph::dfs(int course, std::vector<State>& states) const {
  if (states[static_cast<std::size_t>(course)] == State::Done) return true;
  if (states[static_cast<std::size_t>(course)] == State::InProgress)
    return false;

  states[static_cast<std::size_t>(course)] = State::InProgress;
  const auto& neighbors = adjList_[static_cast<std::size_t>(course)];
  for (const int c : neighbors) {
    if (!dfs(c, states)) return false;
  }
  states[static_cast<std::size_t>(course)] = State::Done;
  return true;
}

}  // namespace grph