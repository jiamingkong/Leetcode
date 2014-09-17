class Solution {
public:
    int singleNumber(int A[], int n) {
        // Convert every integer into a 32 bit number, count the 1s on each digit, take the modulo of 3 for each of the sums.
        // vector<int> bit(32,0);
        int i = 0, result = 0;
        int mask = 1; // used as mask to get the last digit in the bit code.
        for(i =0; i < 32 ; i++)
        {
            int j = 0, count = 0;
            for(j = 0; j < n; j++)
            {
                count += (A[j] >> i) & mask;
            }
            result += ((count % 3) << i);
        }
        return result;
    }
};