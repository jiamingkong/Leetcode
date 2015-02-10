/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator
{
    
public:
    stack<TreeNode*> nodes;
    
public:
    BSTIterator(TreeNode *root)
    {
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext()
    {
        return !nodes.empty();
    }

    /** @return the next smallest number */
    int next()
    {
        TreeNode *X = nodes.top();
        nodes.pop();
        pushLeft(X->right);
        return X->val;
    }

    void pushLeft(TreeNode *x)
    {
        while ( x != NULL)
        {
            nodes.push(x);
            x = x->left;
        }
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */