class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        for (int i = 0; i < k; i++)
        {
            rotateByOne(nums, n);
        }
    }

    void rotateByOne(int nums[], int n) {
        int temp;
        temp = nums[n - 1];
        for(int i = n-1; i > 0; i--)
        {
            nums[i] = nums[i-1];
        }
        nums[0] = temp;
    }
};