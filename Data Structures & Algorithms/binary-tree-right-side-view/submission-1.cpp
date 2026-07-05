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
    vector<int> rightSideView(TreeNode* root);
};

#include <queue>

std::vector<int> Solution::rightSideView(TreeNode* root) {
  if (!root) return {};

  std::vector<int> out{};
  std::queue<TreeNode*> level{};
  level.push(root);

  while (!level.empty()) {
    int size = static_cast<int>(level.size());
    for (int i = 0; i < size; ++i) {
      auto* curr = level.front();
      if (i == 0) {
        out.push_back(curr->val);
      }
      if (curr->right) level.push(curr->right);
      if (curr->left) level.push(curr->left);
      level.pop();
    }
  }

  return out;
}