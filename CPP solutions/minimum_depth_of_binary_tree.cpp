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
    int minDepth(TreeNode *root)
    {
        if (!root) return 0;
        int l_height = minDepth(root->left);
        int r_height = minDepth(root->right);
        if (!l_height)
        {
            return r_height + 1;
        }
        if (!r_height)
        {
            return l_height + 1;
        }
        return (l_height > r_height ? r_height : l_height) + 1;
    }
};