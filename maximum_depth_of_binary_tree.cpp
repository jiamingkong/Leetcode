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
    int maxDepth(TreeNode *root)
    {
        if (root == NULL) return 0;
        int lmax = maxDepth(root->left);
        int rmax = maxDepth(root->right);
        return lmax > rmax ? lmax + 1 : rmax + 1;
    }
};