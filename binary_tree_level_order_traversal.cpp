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
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        /*Breadth first search
        Two variables really mattered here:
            - tracker that stored the pointers of TreeNodes as we traverse a upper level.
            - current_level that stored the values of TreeNodes we traversed.

        In tracker we will put in NULL anytime we swept through a level.
        For each node we collect the value, queue the left, queue the right, go to the next node in tracker.
        If the next node is NULL and the size of the tracker happend to be zero, the tree is done.

        */
        vector<vector<int>> result;
        queue<TreeNode *> tracker; // used as job list
        vector<int> current_level;

        if (root)
        {
            tracker.push(root);
            tracker.push(NULL);
        }

        while (tracker.size())
        {
            TreeNode *cur = tracker.front();
            tracker.pop();

            if (cur)
            {
                current_level.push_back(cur->val);
                if (cur->left) tracker.push(cur->left);
                if (cur->right) tracker.push(cur->right);
            }
            else
            {
                result.push_back(current_level);
                current_level.erase(current_level.begin(), current_level.end());
                if (tracker.size()) tracker.push(NULL);
            }
        }

        return result;
    }
};