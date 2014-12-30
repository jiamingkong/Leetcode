class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (A[mid] == target) return mid;
            if (A[mid] > target)
            {
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return l;
    }
};