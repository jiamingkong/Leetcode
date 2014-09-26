class Solution:
    # @param A, a list of integers
    # @param target, an integer to be inserted
    # @return integer

    def searchInsert(self, A, target):
        left, right = 0, len(A) - 1

        while left <= right:
            mid = int((left + right) / 2)

            if A[mid] == target:
                return mid

            if A[mid] > target:
                right = mid - 1
            else:
                left = mid + 1

        return left

# if __name__ == '__main__':
# 	print Solution().searchInsert([1,3,4], 4)