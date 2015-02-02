class Solution:
    # @return a string
    def convertToTitle(self, num):
        if num < 1:
            return None
        result = ""
        while True:
            if num > 26:
                num, r = divmod(num - 1, 26)
                result = chr(r + ord('A')) + result
            else:
                return chr(num + ord('A') - 1) + result