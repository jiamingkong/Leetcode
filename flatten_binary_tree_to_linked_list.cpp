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
    void flatten(TreeNode *root)
    {

        /*
        Pre-order flatten means try left before right.

        From :
             1
            / \
           2   5
          / \   \
         3   4   6

        To  :
               1
                \
                 2
                  \
                   3
                    \
                     4
                      \
                       5
                        \
                         6

        Here is my approach:
        read node (1); put the right side tree in my pocket. (5)
        proceed left side. (2)

        Now (2) also has left and right, put right side tree (4) in my pocket.
        proced left side (3)

        Looks like (3) is the leaf, put (3) to the right of (2).
        Looks like I have (4) in my pocket, put(4) after (3).

        Looks like I have (5) in my pocket, put(5) after(3).

        Now I am at (5), try left == NULL. try right and I get (6). put(6) after (5).

        -----------------------------------------------------------------------------

        To abstract that, we need to keep track of two things:
        1. pocket
        2. visiting node.

        then we can start the recursion.

        ------------------------------------------------------------------------------*/

        if (!root) return;
        TreeNode *pocket = NULL;
        link(root, pocket);
    }

    void link(TreeNode *node, TreeNode *&pocket)
    {
        if (!node)
        {
            return;
        }

        TreeNode *rightTree = node->right;
        if (pocket)
        {
            pocket->right = node;
            pocket->left = NULL;
        }

        pocket = node;

        link(node->left, pocket);
        link(rightTree, pocket);
    }
};