class Solution {
public:
    int reverse(int x) {
    	// probably the easiest one...
    	// 123 = 100 * 1 + 10 * 2 + 1 * 3;
    	// result-> 3 * 100 + 2 * 10 + 1 * 1 = 321;
        int result =0;
        while(x != 0)
        {
        	int digit = x % 10;
        	result = result * 10 + digit;
        	x /= 10;
        }
        return result;
    }
};