// Given two sorted arrays, put B into A, assume A has enough space to hold things.

// Do it from back to front to save time.

class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        int k = m + n - 1;
        int i = m - 1, j = n - 1;

        for (; i >= 0 && j >= 0; k--)
        {
            if (A[i] >= B[j])
            {
                A[k] = A[i];
                i--;
            }
            else
            {
                A[k] = B[j];
                j--;
            }
        }

        while (j >= 0)
        {
            A[k] = B[j];
            k--; j--;
        }
    }
};