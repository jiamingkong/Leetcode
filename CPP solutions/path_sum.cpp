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
    bool hasPathSum(TreeNode *root, int sum) {
        return hasPathSum(root, 0, sum);
    }

    bool hasPathSum(TreeNode *root, int already_have, int target)
    {

        // reaching out of the tree.
        if (root == NULL)
        {
            return false;
        }

        already_have += root->val;

        // reaching a leave.
        if (root->left == NULL && root->right == NULL)
        {
            if (already_have == target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        // I can even further cut off some branches if the values are non-negative.
        return hasPathSum(root->left, already_have, target) || hasPathSum(root->right, already_have, target);
    }
};