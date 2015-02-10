class Solution:
    # @param digits, a list of integer digits
    # @return a list of integer digits
    def plusOne(self, digits):
        result = []
        carry = 1
        base = 10
        for i in digits[::-1]:
            result.append((i+carry) % base)
            carry = (i + carry) / base
        if carry != 0:
            result.append(carry)
        return result[::-1]

# if __name__ == '__main__':
#     a = Solution()
#     print a.plusOne([0])