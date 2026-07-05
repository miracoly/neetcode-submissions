/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root);
};

#include <queue>

std::vector<std::vector<int>> Solution::levelOrder(TreeNode* root) {
  if (!root) return {};

  std::vector<std::vector<int>> out{};
  std::queue<TreeNode*> queue{};
  queue.push(root);

  while (!queue.empty()) {
    int size = static_cast<int>(queue.size());
    std::vector<int> level{};
    level.reserve(static_cast<std::size_t>(size));
    for (int i = 0; i < size; ++i) {
      auto* curr = queue.front();
      queue.pop();
      level.push_back(curr->val);
      if (curr->left) queue.push(curr->left);
      if (curr->right) queue.push(curr->right);
    }
    out.push_back(level);
  }

  return out;
}
