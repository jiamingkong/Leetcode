/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/*
Something like the mirror of construct_binary_tree_from_inorder_and_postorder_traversal

the first element in preorder must be the root
use this to split the inorder
and recursively do it.*/


class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode *buildTree(vector<int> &preorder,
                        vector<int> &inorder,
                        int start_pre,
                        int end_pre,
                        int start_in,
                        int end_in)
    {
        if (end_pre < start_pre || end_pre - start_pre != end_in - start_in)
        {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[start_pre]);

        int splitter = -1;
        for (int i = start_in; i <= end_in; ++i)
        {
            if (inorder[i] == root->val)
            {
                splitter = i;
                break;
            }
        }


        if (splitter != -1)
        {
            int left = splitter - start_in;
            root->left = buildTree(preorder,
                                   inorder,
                                   start_pre + 1,
                                   start_pre + left,
                                   start_in,
                                   splitter - 1);
            root->right = buildTree(preorder,
                                    inorder,
                                    start_pre + left + 1,
                                    end_pre,
                                    splitter + 1,
                                    end_in);
        }
        return root;
    }
};