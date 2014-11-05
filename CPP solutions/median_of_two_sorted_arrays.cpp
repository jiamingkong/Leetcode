class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        if (n > m) return findMedianSortedArrays(B, n, A, m);

        int k = (n + m - 1 ) / 2;
        int l = 0, r = min(k, n);

        while (l < r)
        {
            int midA = (l + r) / 2;
            int midB = k - midA;
            if (midB > k || A[midA] < B[midB])
                l = midA + 1;
            else
                r = midA;
        }

        int a = max( l > 0 ? A[l - 1] : INT_MIN, k - l >= 0 ? B[k - 1] : INT_MIN);
        if (((n + m) & 1) == 1)
        {
            return a;
        }

        int b = min(l < n ? A[l] : INT_MAX, k - l + 1 < m ? B[k - l + 1] : INT_MAX);

		return (a + b) / 2;
    }

    int min(int a, int b)
    {
        return a > b ? b : a;
    }

    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};