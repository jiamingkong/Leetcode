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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        /*
            3
           / \
          9  20
            /  \
           15   7

        [
          [3],
          [20,9],
          [15,7]
        ]

        My simplest solution will be using two stacks to queue jobs.
        root-->stack1
        -------------
        current job : stack1.top()->node


        stack2 : if next round is going left to right, add node.left, node.right,
        else add node.right, node.left.

        do this for each of nodes in stack1, and collect their value as we sweep through it.

        -------------
        Now we reach the end of stack1. change sweeping direction.
        add the collector to the result.
        swap(stack1, stack2)
        repeat until they are both empty.

        Example:
        stack1->[3]
        stack2->[20, 9]
        collector->[[3]]

        swap: stack1:[20,9], stack2 empty
        repeat:

        stack1->[20]     [9]
        stack2->[15, 7]  *[NULL, NULL]*
        collector-> [[3],[20,9]]

        swap: stack1:[15, 7], stack2 empty
        repeat


        */

        vector<vector<int> > result;
        if (!root) return result;

        stack<TreeNode *> this_stack, next_stack;
        vector<int> current_level;


        int left_right = 1;
        this_stack.push(root);

        while (!this_stack.empty())
        {
            TreeNode *cur = this_stack.top();
            this_stack.pop();
            current_level.push_back(cur->val);

            if (left_right % 2 == 1)
            {
                if (cur->left) next_stack.push(cur->left);
                if (cur->right) next_stack.push(cur->right);
            }
            else
            {
                if (cur->right) next_stack.push(cur->right);
                if (cur->left) next_stack.push(cur->left);
            }

            if (this_stack.empty())
            {
                stack<TreeNode *> t;
                t = next_stack;
                next_stack = this_stack;
                this_stack = t;

                result.push_back(current_level);
                current_level.erase(current_level.begin(), current_level.end());
                left_right++;
            }
        }

        return result;
    }
};