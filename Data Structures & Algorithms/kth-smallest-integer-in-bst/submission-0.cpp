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
    int kthSmallest(TreeNode* root, int k);

private:
    void traverse(TreeNode* node, std::vector<int>& out);
};

int Solution::kthSmallest(TreeNode* root, int k) {
  if (k < 1) return 0;

  std::vector<int> values{};
  traverse(root, values);
  if (k > values.size()) return 0;
  return values[k - 1];
}

void Solution::traverse(TreeNode* node, std::vector<int>& out) {
  if (!node) return;

  traverse(node->left, out);
  out.push_back(node->val);
  traverse(node->right, out);
};

