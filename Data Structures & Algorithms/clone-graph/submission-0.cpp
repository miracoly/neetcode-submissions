/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
 public:
  static Node* cloneGraph(Node* node);

 private:
  static Node* dfs(Node* node, std::unordered_map<Node*, Node*>& visited);
};

Node* Solution::cloneGraph(Node* node) {
  std::unordered_map<Node*, Node*> visited{};
  return dfs(node, visited);
}

Node* Solution::dfs(Node* node, std::unordered_map<Node*, Node*>& visited) {
  if (node == nullptr) return nullptr;
  if (visited.contains(node)) return visited[node];

  Node* clone = new Node(node->val);
  visited[node] = clone;
  clone->neighbors.reserve(node->neighbors.size());
  for (auto* const nb : node->neighbors) {
    clone->neighbors.push_back(dfs(nb, visited));
  }
  return clone;
}

