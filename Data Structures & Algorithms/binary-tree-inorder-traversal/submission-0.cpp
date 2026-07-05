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
    vector<int> inorderTraversal(TreeNode* root);
 private:
  void traverse(TreeNode* node, std::vector<int>& out);

};

std::vector<int> Solution::inorderTraversal(TreeNode* root) {
  std::vector<int> out{};
  traverse(root, out);
  return out;
}

void Solution::traverse(TreeNode* node, std::vector<int>& out) {
  if (!node) return;

  traverse(node->left, out);
  out.push_back(node->val);
  traverse(node->right, out);
};
