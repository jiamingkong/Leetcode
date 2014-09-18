/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


/*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25. 

*/   



class Solution {
public:
    int sumNumbers(TreeNode *root) {
    	int sum =0, path = 0;
    	calc(root, sum, path);
    	return sum;
    }


    void calc(TreeNode *node, int &sum, int path)
    {
    	if(!node) return;
    	path = path * 10 + node->val;
    	if(!node->left && !node->right)
    	{
    		sum += path;
    		return;
    	}

    	calc(node->left, sum, path);
    	calc(node->right, sum, path);
    }

};