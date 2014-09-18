class Solution {
public:
    string addBinary(string a, string b)
    {
        string result;
        int carry = 0;

        int i = a.size() - 1, j = b.size() - 1;
        int a_digit, b_digit;
        for (; i >= 0 || j >= 0; i--, j--)
        {
            if (i >= 0)
            {
                a_digit = a[i] - '0';
            }
            else
            {
                a_digit = 0;
            }
            if (j >= 0)
            {
                b_digit = b[j] - '0';
            }
            else
            {
                b_digit = 0;
            }
            int new_digit = (a_digit + b_digit + carry) % 2;
            carry = (a_digit + b_digit + carry) / 2;
            result.insert(result.begin(), new_digit + '0');


        }
        if (carry)
        {
            result.insert(result.begin(), '1');
        }
        return result;
    }
};