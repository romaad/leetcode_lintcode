class Solution {
private:
        const int TR = 1, FLS = 0, NTST = -1;

    bool solve(vector<int>& dp, vector<int>& nums, int idx) {
        if(dp[idx] != NTST) {
            return dp[idx];
        }
        bool res = false;
        for (int i =1; i <= nums[idx]; i++) {
                int  jump = idx + i;
                if (jump >= nums.size() -1) {
                    res = true;
                    break;
                }
                if (solve(dp, nums, jump)) {
                    res = true;
                    break;
                }
        }
        return dp[idx] = res? TR : FLS;
    }
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) {
            return true;
        }
        vector<int> dp(nums.size()+1, -1);
        return solve(dp, nums, 0);
    }
};

// another solution is to use gas approach 
/**
int gas = 0;
for (int i = 0; i< n ;i++) {
  if (0 > gas) {
    return false;
  }
  if (nums[i] > gas) {
    gas = nums[i];
  }
  gas -= 1;
}
return true;
*/
