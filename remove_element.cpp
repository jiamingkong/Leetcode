class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Use a second indexer to do the copy work
        int idx = 0;
        int i = 0;
        for(i = 0; i < n; i++)
        {
        	if (A[i] == elem)
        	{
        		continue;
        	}
        	// if the element is found, the indexer is not getting ++.
        	A[idx] = A[i];
        	idx++; 
        }
        return idx;
    }
};