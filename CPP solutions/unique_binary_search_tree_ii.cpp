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
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return *generate(1, 0);
        return *generate(1, n);
    }

    vector<TreeNode *> *generate(int start, int end)
    {
        vector<TreeNode *> *result = new vector<TreeNode *>();

        if (start > end)
        {
            result->push_back(NULL);
            return result;
        }

        int i = start;
        for (; i <= end; i++)
        {
            vector<TreeNode *> *leftSubs = generate(start, i - 1);
            vector<TreeNode *> *rightSubs = generate(i + 1, end);

            int j = 0;
            for (; j < leftSubs->size(); j++)
            {
                int k = 0;
                for (; k < rightSubs->size(); k++)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = (*leftSubs)[j];
                    node->right = (*rightSubs)[k];
                    result->push_back(node);
                }
            }
        }

        return result;
    }
};