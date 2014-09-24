class Solution {
public:
    double pow(double x, int n) {
        /*This problem is relatively simple, the n here must be integer which helps a lot.
        Say I want X^397, instead of doing result *= x for 397 times, a faster way works like :
        x^397 = x^198 * x^198 * x
              = (x^98 * x^98) ^ 2 * x
              = ....
              */


        if (n < 0)
            return 1.0 / power(x , -n);
        else
            return power(x, n);
    }

    double power(double x, int n)
    {
        if (n == 0) return 1;
        double v = power(x, n / 2);
        if (n % 2 == 0)
            return v * v;
        else
            return v * v * x;
    }
};