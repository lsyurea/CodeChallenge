class Solution {
public:
    int myAtoi(string s) {
        int res = 0, cur;
        bool isPositive = true;
        bool isStart = false;
        for (char c : s) {
            // check if doesnt overflow
            if (!isStart && c == ' ') continue;
            if (!isStart && c == '-') {
                isPositive = false;
                isStart = true;
                continue;
            } 
            if (!isStart && c == '+') {
                isPositive = true;
                isStart = true;
                continue;
            } 
            // actual int val
            cur = (int) c - 48;
            if (cur > 9 || cur < 0) return isPositive ? res : -res;
            if (!isStart) isStart = true;
            if (res > INT_MAX / 10) return isPositive ? INT_MAX : INT_MIN;
            res *= 10;
            if (res > INT_MAX - cur) return isPositive ? INT_MAX : INT_MIN;
            res += cur;
        }
        return isPositive ? res : -res;
    }
};