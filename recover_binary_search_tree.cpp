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
    void recoverTree(TreeNode *root) {
        /*I have no idea how to do this in constant space. Shoot for O(n) first.*/

        vector<TreeNode *> list;
        vector<int> values;

        traverse(root, list, values);
        sort(values.begin(), values.end());

        int i =0;
        for(; i < values.size(); i++)
        {
        	list[i]->val = values[i];
        }

    }

    void traverse(TreeNode *root, vector<TreeNode *> &list, vector<int> &values)
    {
    	if(!root) return;

    	traverse(root->left, list, values);
    	list.push_back(root);
    	values.push_back(root->val);
    	traverse(root->right, list, values);

    }
};