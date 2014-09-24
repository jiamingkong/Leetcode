/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        /*        I can be lazy and plug the linked list into an array first, then re - use my code.

                But I decided to re - do it in a different manner.

                    1->2->3->4->5


                    3
                    / \
                    2   4
                    /     \
                    1       5

                    This is simple example but enough to tell the story.

                    build (1, NULL, NULL)
                    build (2, (1), NULL)
                    build (3, (2), NULL)
                    ---- at the middle of the linked list
                    build (4, NULL, NULL), append(4, 3->right)
                    build (5, NULL, NULL), append(5, 4->right)
        */
        int len = 0;
        ListNode *p = head;
        while(p)
        {
        	len++;
        	p = p->next;
        }

        return build_branch(head, 0, len - 1);
    }

    TreeNode *build_branch(ListNode *&head, int start , int end)
    {
    	if(start >= end) return NULL;
    	int mid = (start + end) / 2;
    	TreeNode *leftChild = build_branch(head, start, mid-1);
    	TreeNode *node = new TreeNode(head->val);

    	node->left = leftChild;
    	head = head->next;

    	node->right = build_branch(head, mid + 1, end);

    	return node;
    }
};