class Solution:
    # @param s, a string
    # @return a string
    def reverseWords(self, s):
        words = s.split(" ")
        return " ".join([i for i in words[::-1] if i != ""])