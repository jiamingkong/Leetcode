class Solution:
    # @param A, a list of integer
    # @return an integer

    # Just use the XOR operator. XOR(A, XOR(B, A)) = B

    def singleNumber(self, A):
        result = A[0]
        for i in A[1:]:
            result ^= i
        return result
