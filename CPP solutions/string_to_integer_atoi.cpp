class Solution {
public:
    int atoi(const char *str) {
        if (!str) return 0;

        int i = 0;
        bool pos = true;
        int res = 0;

        while (str[i] == ' ') i++;
        if (str[i] == '+') {
            pos = true;
            i++;
            if(str[i] == '-') return 0;
        }
        if (str[i] == '-') {
            pos = false;
            i++;
            if(str[i] == '+') return 0;
        }

        if (!isdigit(str[i])) {
            return 0;
        }

        while (isdigit(str[i]))
        {
            if (pos && res > INT_MAX / 10) {
                return INT_MAX;
            }
            if (pos && res == INT_MAX / 10 && int(str[i] - '0') >= 7) {
                return INT_MAX;
            }
            if (!pos && -res < INT_MIN / 10) {
                return INT_MIN;
            }
            if (!pos && -res == INT_MIN / 10 && int(str[i] - '0') >= 8) {
                return INT_MIN;
            }
            res = res * 10 + int(str[i] - '0');
            i++;
        }
        if (pos) {
            return res;
        }
        else {
            return -res;
        }
    }
};