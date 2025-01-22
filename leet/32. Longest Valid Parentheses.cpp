/**
The idea here is that if any valid subsequence would be preceeded by erroneous closing parentheses like:
-- error marked with []
[)))(((] () 
or would be followed erroneous opening ones like:
() [)))((]
what we do is that we go from left to right, ignoring erroneous closing parentheses and go from right to left ignoring erroneous opening ones
  */

class Solution {
private:
inline void update_vals(
    int &sum, int & count, int &maxSum, int& val
) {
    sum += val;
    if (sum < 0 ){
        count = 0;
        sum = 0;
    }
    else if (sum == 0 ){
        count++;
        maxSum = max(maxSum,count);
    } else {
        count++;
    }
}
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        int sum = 0, maxSum = 0, count = 0;
        for (int i =0; i< n ; i++) {
            int val = s[i] == ')'? -1 : 1;
            update_vals(sum, count, maxSum, val);
        }
        sum =0; count =0;
        for (int i = n-1; i > -1; i--) {
            int val = s[i] == ')'? 1 : -1;
            update_vals(sum, count, maxSum, val);
        }
        return maxSum;
    }
};
