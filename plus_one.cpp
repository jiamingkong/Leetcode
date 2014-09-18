class Solution {
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // Only one thing to worry. What if the result is one digit longer than the given number?
        int carry = 1;
        int current_digit = 0;
        int n = digits.size();

        int BASE = 10;
        vector<int> result(n, 0);
        int i = 0;
        for (i = n - 1; i >= 0; i--)
        {
            current_digit = digits[i] + carry;
            carry = current_digit / BASE;
            result[i] = current_digit % BASE;
        }
        if (carry == 1)
        {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};

