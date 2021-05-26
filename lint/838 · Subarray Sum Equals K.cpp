class Solution {
public:
    /**
     * @param nums: a list of integer
     * @param k: an integer
     * @return: return an integer, denote the number of continuous subarrays whose sum equals to k
     */
    int subarraySumEqualsK(vector<int> &nums, int k) {
        // write your code here
        int sum = 0;
        unordered_map<int,int> mp;
        int cnt = 0;
        mp[0] = 1;
        for(int num : nums) {
            sum += num;
            cnt += mp[sum-k];
            mp[sum]++;
        }
        return cnt;
    }
};
