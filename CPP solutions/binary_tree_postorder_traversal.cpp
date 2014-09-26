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
    vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
        if (!root) return result;
        traverse(result, root);
        return result;
    }
    void traverse(vector<int> &result, TreeNode *root)
    {
        if (root->left) traverse(result, root->left);
        if (root->right) traverse(result, root->right);
        result.push_back(root->val);
    }
};