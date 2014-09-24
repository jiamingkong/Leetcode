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
    TreeNode *sortedArrayToBST(vector<int> &num) {

        /*      Put the middle of the array into root.
                Put the middle of the left part into root->left
                Put the middle of the right part into root->right
        */
        return build_branch(num, 0, num.size() - 1);
    }

    TreeNode *build_branch(vector<int> &num, int start, int end)
    {
        if (start > end) return NULL;
        if (start == end) return new TreeNode(num[start]);
        int mid = (start + end) / 2;
        TreeNode *node = new TreeNode(num[mid]);
        node->left = build_branch(num, start, mid - 1);
        node->right = build_branch(num, mid + 1, end);
        return node;
    }
};