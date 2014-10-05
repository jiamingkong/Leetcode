class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        std::transform(s.begin(), s.end(), s.begin(), ::tolower);  
        while (start < end)
        {
            while (start < end && !isChar(s[start])) start++;
            while (start < end && !isChar(s[end])) end--;
            if (s[start] != s[end]) break;
            start ++;
            end --;

        }
        if (start >= end)
        {
            return true;
        }
        return false;
    }

    bool  isChar(char c)
    {
        if ((c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9'))
        {
            return true;
        }
        return false;
    }
};