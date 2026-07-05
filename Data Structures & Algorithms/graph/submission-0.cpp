class Graph {
 public:
  Graph();
  void addEdge(int src, int dst);
  bool removeEdge(int src, int dst);
  bool hasPath(int src, int dst);

 private:
  std::unordered_map<int, std::unordered_set<int>> mAdjList;
  bool dfs(int src, int dst, std::unordered_set<int>& visited);
};

Graph::Graph() = default;

void Graph::addEdge(int src, int dst) {
  mAdjList[src].insert(dst);
  mAdjList[dst];
}

bool Graph::removeEdge(int src, int dst) {
  const auto edge = mAdjList.find(src);
  if (edge == mAdjList.end()) return false;

  const auto count = edge->second.erase(dst);
  return count > 0;
}

bool Graph::hasPath(int src, int dst) {
  std::unordered_set<int> visited;
  return dfs(src, dst, visited);
}

bool Graph::dfs(int src, int dst, std::unordered_set<int>& visited) {
  if (src == dst) return true;
  if (visited.contains(src)) return false;

  visited.insert(src);
  const auto vertex_it = mAdjList.find(src);
  if (vertex_it == mAdjList.end()) return false;

  for (const auto& vx : vertex_it->second) {
    if (dfs(vx, dst, visited)) return true;
  }

  return false;
}
