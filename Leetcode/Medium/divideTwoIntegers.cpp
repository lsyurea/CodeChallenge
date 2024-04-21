class Solution {
public:
    int divide(int dividend, int divisor) {
        bool isPositive;
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
            isPositive = true;
        } else {
            isPositive = false;
        }

        dividend = abs(dividend);
        divisor = abs(divisor);

        // note that there are inputs that violates the constraints in leetcode
        long res = 0;
        long cur, temp, val;
        int max_int = numeric_limits<int>::max();
        int min_int = numeric_limits<int>::min();
        while (dividend > 0) {
            temp = divisor;
            val = 1;
            while (temp < dividend) {
                cur = temp << 1;
                
                if (cur >= dividend) break;
                temp <<= 1;
                val <<= 1;
            }
            res += val;
            dividend -= temp;
        }
        if (dividend < 0) {
            res -= val;
        }
        if (res > max_int) return isPositive ? max_int : min_int;
        return isPositive ? res : -res;
    }
};