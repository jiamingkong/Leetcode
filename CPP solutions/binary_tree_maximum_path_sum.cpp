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
    int maxPathSum(TreeNode *root)
    {
        int current = INT_MIN;

        int result = depth_first(root, current);
        return current;
    }

    int depth_first(TreeNode *node, int &current)
    {
        if (!node) return 0;

        int left_sum = depth_first(node->left, current);
        int right_sum = depth_first(node->right, current);
        int node_value = node->val;

        if (left_sum > 0) node_value += left_sum;
        if (right_sum > 0) node_value += right_sum;
        if (node_value > current) current = node_value;

        int temp = left_sum > right_sum ? left_sum : right_sum;
        return temp > 0 ? temp + node->val : node ->val;
    }
};