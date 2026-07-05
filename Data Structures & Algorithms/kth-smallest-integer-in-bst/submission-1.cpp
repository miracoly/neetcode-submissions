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
      void traverse(TreeNode* node, std::pair<int, int>& tmp);
};

int Solution::kthSmallest(TreeNode* root, int k) {
  if (k < 1) return 0;

  std::pair<int, int> tmp{k, 0};
  traverse(root, tmp);
  return tmp.second;
}

void Solution::traverse(TreeNode* node, std::pair<int, int>& tmp) {
  if (!node) return;

  traverse(node->left, tmp);
  tmp.first--;
  if (tmp.first == 0) {
    tmp.second = node->val;
    return;
  }
  traverse(node->right, tmp);
};


