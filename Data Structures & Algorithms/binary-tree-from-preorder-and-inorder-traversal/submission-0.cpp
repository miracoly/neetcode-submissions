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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);
private:
  static TreeNode* buildSubtree(const std::vector<int>& preorder, int inL,
                                int inR, int& preCur,
                                const std::unordered_map<int, int>& inPos);
};

#include <unordered_map>

static std::unordered_map<int, int> toIndexMap(
    const std::vector<int>& inorder) {
  std::unordered_map<int, int> out{};
  out.reserve(inorder.size());

  for (int i = 0; i < static_cast<int>(inorder.size()); ++i) {
    out[inorder[static_cast<std::size_t>(i)]] = i;
  }
  return out;
}

TreeNode* Solution::buildTree(std::vector<int>& preorder,
                              std::vector<int>& inorder) {
  if (preorder.size() < 1 || inorder.size() < 1) return nullptr;

  std::unordered_map<int, int> inPos = toIndexMap(inorder);
  int preCur = 0;
  return buildSubtree(preorder, 0, static_cast<int>(inorder.size() - 1), preCur,
                      inPos);
}

TreeNode* Solution::buildSubtree(const std::vector<int>& preorder, int inL,
                                 int inR, int& preCur,
                                 const std::unordered_map<int, int>& inPos) {
  if (inL > inR) return nullptr;

  int rootVal = preorder[static_cast<std::size_t>(preCur)];
  ++preCur;
  int mid = inPos.at(rootVal);
  auto* root = new TreeNode(rootVal);
  root->left = buildSubtree(preorder, inL, mid - 1, preCur, inPos);
  root->right = buildSubtree(preorder, mid + 1, inR, preCur, inPos);

  return root;
}

