class Solution:
    # @return an integer

    def numTrees(self, n):
        dp_array = [0] * (n + 1)
        dp_array[0] = 1
        dp_array[1] = 1
        for i in xrange(2, n + 1):
            for j in xrange(0, i):
                dp_array[i] += dp_array[j] * dp_array[i - j - 1]

        return dp_array[n]
