class Solution {
public:
    int singleNumber(int A[], int n)
    {
        // easy, use the XOR bit operator. Two rules applied here:
        // XOR(A, A) = 0 , XOR(XOR(A, B), A) = B

        int res = A[0], i = 0;
        for (i = 1; i < n; i++)
        {
            res ^= A[i];
        }

        return res;
    }
};