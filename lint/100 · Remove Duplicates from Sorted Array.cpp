class Solution {
public:
    /*
     * @param nums: An ineger array
     * @return: An integer
     */
    int removeDuplicates(vector<int> &nums) {
        // write your code here
      // i do easy stuff too, just to restore self esteem
        int cnt = 0;
        int n = nums.size();
        int next = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[i-1]) {
                cnt++;
            }else{
                nums[next++] = nums[i];
            }
        }
        return n - cnt;
    }
};
