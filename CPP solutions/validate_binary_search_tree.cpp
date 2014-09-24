/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        /*valid BST must be:
        For each node:
        1, left branch contains nothing bigger than self.val
        2, right branch contains nothing smaller than self.val
        3, isValidBST(left) && isValidBST(right)
        recursion.

        */

        return isValidBranch(root, INT_MIN, INT_MAX);
    }

    bool isValidBranch(TreeNode *node, int &MIN, int &MAX)
    {
        if (!node) return true;

        if (node->val > MIN &&
                node->val < MAX &&
                isValidBranch(node->left, MIN, node->val) &&
                isValidBranch(node->right, node->val, MAX))
            return true;
        else
            return false;
    }
};