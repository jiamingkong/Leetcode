class Solution {
public:
    int jump(int A[], int n) {
        int start = 0;
        int end = 0;
        int count = 0;

        if (n==1)
        {
            return 0;
        }

        while(end < n)
        {
            int max = 0;
            count++;
            int i = start;
            for(; i <= end; i++)
            {
                if(A[i] + i >= n-1)
                {
                    return count;
                }

                if(A[i] + i > max)
                {
                    max = A[i] + i;
                }
            }

            start = end + 1;
            end = max;
        }
    }
};