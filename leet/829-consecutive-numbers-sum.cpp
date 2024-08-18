/**
solution by @ntcie
n, a sum of k consecutive integers starting from a, can be expressed as:

n=a+(a+1)+(a+2)+⋯+(a+k−1)

Using the arithmetic sequence formula:

n=k⋅a+ 2k⋅(k−1)
k⋅a=n−k/2⋅(k−1)
a = (n−k/2⋅(k−1))/k 
For a to be a positive integer, the numerator must be divisible by k and the result must be positive. Therefore, we need to check for each k in the equation from 1 to the point where  
k/2⋅(k−1) exceeds n (we do not want the numerator to be negative).
  */
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int cnt = 0;
        for (int k = 1; 2*n > k*(k-1); k++) {
            if ((n - k*(k-1)/2 )%k == 0) {
                cnt ++;
            }
        }
        return cnt;
    }
};
