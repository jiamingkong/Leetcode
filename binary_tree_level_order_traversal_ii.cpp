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
    vector<vector<int> > levelOrderBottom(TreeNode *root)
    {
        // I am going to use what ever I have in binary_tree_level_order_traversal.cpp, get the result and revert it....

        list<vector<int>> result;
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
                result.push_front(current_level);
                current_level.erase(current_level.begin(), current_level.end());
                if (tracker.size()) tracker.push(NULL);
            }
        }


        vector<vector<int>> reversed_result;
        list<vector<int>>::iterator itr = result.begin();
        for (itr = result.begin(); i != result.end(); i++)
        {
            reversed_result.push_back(*itr);
        }

        return reversed_result;
    }
};