// trivial math no explanation needed
class Solution {
public:
    int reverse(int x) {
        int res = 0;
        bool sign = x > 0;
        while (x) {
            int val = x % 10;
            x /= 10;
            if ((sign && res <= INT_MAX / 10) || (!sign && res >= INT_MIN / 10)) {
                res *= 10;
                res += val;
            } else {
                return 0;
            }
        }
        return res;
    }
};
