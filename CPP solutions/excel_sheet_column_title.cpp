class Solution {
public:
    string convertToTitle(int n) {
        vector<int> numbers;
        int remainder = INT_MAX;
        while(n > 26)
        {
            int other = n / 26;
            numbers.push_back(n - other * 26);
            n = other;
        }
    }
};