// Same as populating_next_right_pointers_in_each_node.cpp


/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void link(TreeLinkNode *root) {
        // safe
        if (!root) return;

        // If this is a root of anything, the right side should be the edge of the tree. Just render the right->next as NULL and we will be fine. If there is left node, the left->next is easily right.
        if (root->next == NULL)
        {
            if (root->right) {
                root->right->next = NULL;
            }
            if (root->left) {
                root->left->next = root->right;
            }
        }
        else
        {

            // Now this gets a little bit funny.
            TreeLinkNode *p = root->next;
            TreeLinkNode *q = NULL;

            // if it already has next node, that means it is inside the tree. Now we will go sweep the level.
            while (p)
            {
                if (p->left) {
                    q = p->left;
                    break;
                }
                if (p->right) {
                    q = p->right;
                    break;
                }
                p = p->next;
            }
            if (root->right) {
                root->right->next = q;
            }
            if (root->left && root->right) {
                root->left->next = root->right;
            }
            if (root->left && !root->right) {
                root->left->next = q;
            }
        }

        link(root->right);
        link(root->left);
    }

    void connect(TreeLinkNode *root)
    {
        if (!root) return;
        root->next = NULL;
        link(root);
    }
};