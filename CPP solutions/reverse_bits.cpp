class Solution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t result = 0;
		uint32_t base = 2147483648;
		while (n)
		{
			if (n & 1)
			{
				result += base;
			}
			n >>= 1;
			base /= 2;
		}
		return result;
	}
};