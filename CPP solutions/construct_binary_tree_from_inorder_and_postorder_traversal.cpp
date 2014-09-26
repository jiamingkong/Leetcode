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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return buildTree(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }


    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder, int start_in, int end_in, int start_post, int end_post)
    {
        if (end_in < start_in || end_in - start_in != end_post - start_post)
        {
            return NULL;
        }

        // the end of postorder must be the root.
        TreeNode *root = new TreeNode(postorder[end_post]);

        // split the left tree and right tree in the inorder.
        int splitter = -1;

        for (int i = start_in; i <= end_in; ++i)
        {
            if (inorder[i] == root->val)
            {
                splitter = i;
                break;
            }
        }

        // ----- if not split, this is the leave. return it and end.
        if (splitter == -1)
        {
            return root;
        }
        // ----- build trees.
        int length = splitter - start_in;
        root->left = buildTree(inorder, postorder, start_in, splitter - 1, start_post, start_post + length - 1);
        root->right = buildTree(inorder, postorder, splitter + 1, end_in, start_post + length, end_post - 1);

        return root;
    }
};