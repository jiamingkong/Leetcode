class Solution {
public:
    bool canJump(int A[], int n) {
        int maxCover = 0;
        int start = 0;
        for (; start <= maxCover && start < n ; start++)
        {
            if (A[start] + start > maxCover)
            {
                maxCover = A[start] + start;
            }
            if (maxCover >= n - 1)
            {
                return true;
            }
        }

        return false;
    }
};