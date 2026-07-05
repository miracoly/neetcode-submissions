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
    bool hasPathSum(TreeNode* root, int targetSum);
private:
    bool hasPathSum(TreeNode* root, int targetSum, int currSum);
};

bool Solution::hasPathSum(TreeNode* root, int targetSum) {
  return hasPathSum(root, targetSum, 0);
}

bool Solution::hasPathSum(TreeNode* root, int targetSum, int currSum) {
  if (root == nullptr) return false;
  currSum += root->val;

  if (!root->left && !root->right) return currSum == targetSum;
  if (hasPathSum(root->left, targetSum, currSum)) return true;
  if (hasPathSum(root->right, targetSum, currSum)) return true;

  return false;
}
