class Solution {
public:
    /**
     * @param nums: a binary array
     * @return: the maximum length of a contiguous subarray
     */
    int findMaxLength(vector<int> &nums) {
        unordered_map<int, int> sums;
        int cur = 0;
        int maxlen = 0;
        sums[0] = -1;
        //off by 1s ugh
        for(int i = 0 ; i < nums.size() ; i++) {
            cur += (nums[i]? 1 : -1);
            if(sums.find(cur) == sums.end()) {
                sums[cur] = i;
            }else if ( i - sums[cur] > maxlen) {
                maxlen = i - sums[cur];
            }
        }
        return maxlen;
    }
};
