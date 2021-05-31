class Solution {
public:
    /*
     * @param A: An integer array
     * @return: A list of integers includes the index of the first number and the index of the last number
     */
    vector<int> continuousSubarraySum(vector<int> &a) {
        // write your code here
        if(!a.size()) return vector<int>();
        vector<int> ret (2, 0);
        int maxSum = a[0], cur = 0, lo = 0;
        for(int i = 0 ; i < a.size(); i++) {
            cur += a[i];
            if(cur > maxSum){
                maxSum = cur;
                ret[1] = i;
                ret[0] = lo;
            }
            if(cur < 0){
                lo = i + 1;
                cur = 0;
            }
        }
        return ret;
    }
};
