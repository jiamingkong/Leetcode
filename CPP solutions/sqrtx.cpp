class Solution {
public:
    int sqrt(int x) {
        if (x == 0) return 0;
        double last = 0;
        double next = 1;
        while (next != last)
        {
            last = next;
            next = (next + x / next) / 2;
        }

        return int(next);
    }
};