class Solution:
    # @param version1, a string
    # @param version2, a string
    # @return an integer
    def compareVersion(self, version1, version2):
        version_numbers_1 = [int(i) for i in version1.split(".")]
        version_numbers_2 = [int(i) for i in version2.split(".")]
        
        len_1 = len(version_numbers_1)
        len_2 = len(version_numbers_2)
        
        if len_1 < len_2:
            for i in xrange(len_2 - len_1):
                version_numbers_1.append(0)
        if len_1 > len_2:
            for i in xrange(len_1 - len_2):
                version_numbers_2.append(0)
        step = max([len(version_numbers_1), len(version_numbers_2)])
        for i in xrange(0, step):
            if version_numbers_1[i] > version_numbers_2[i]:
                return 1
            elif version_numbers_1[i] < version_numbers_2[i]:
                return -1
        return 0
        