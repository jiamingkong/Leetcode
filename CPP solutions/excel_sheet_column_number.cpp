class Solution {
public:
    int titleToNumber(string s) {
        int n = s.size();
        int result = 0;
        int multiplier = 1;
        for (int i = 0; i < n; i++)
        {
            result += (s[n - i - 1] - 'A' + 1) * multiplier;
            multiplier *= 26;
        }
        return result;
    }
};