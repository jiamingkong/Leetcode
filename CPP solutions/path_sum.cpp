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

    bool hasPathSum(TreeNode *root, int sum, int target)
    {

        // reaching out of the tree.
        if (root == NULL)
        {
            return false;
        }

        sum += root->val;

        // reaching a leave.
        if (root->left == NULL && root->right == NULL)
        {
            if (sum == target)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        // I can even further cut off some branches if the values are non-negative.
        return hasPathSum(root->left, sum, target) || hasPathSum(root->right, sum, target);
    }
};