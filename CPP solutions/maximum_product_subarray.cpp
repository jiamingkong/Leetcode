class Solution {
public:

    int min(int x, int y) {
        return x < y ? x : y;
    }
    int max(int x, int y) {
        return x > y ? x : y;
    }


    int maxProduct(int A[], int n) {
        if (n == 0) return 0;
        if (n == 1) return A[0];


        int max_ending_here = 1;
        int min_ending_here = 1;
        int max_found = INT_MIN;

        int i = 0;

        if (n == 1) return A[0];

        for (; i < n; i++)
        {
            if (A[i] > 0)
            {
                max_ending_here *= A[i];
                min_ending_here *= A[i];
                max_found = max(max_found, max_ending_here);
            }
            else if (A[i] == 0)
            {
                max_found = max(max_found, 0);
                max_ending_here = 1;
                min_ending_here = 1;
            }
            else
            {
                max_found = max(max_found, min_ending_here * A[i]);
                int temp = max_ending_here;
                max_ending_here = max(1, min_ending_here * A[i]);
                min_ending_here = temp * A[i];
            }

        }

        return max_found;
    }
};