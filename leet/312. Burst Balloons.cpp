class Solution {
    int dp[301][301];
    int start(vector<int>& nums, int s, int e) {
        int n = nums.size();
        if (s > e) {
            return 0;
        }
        if (dp[s][e] != -1) {
            return dp[s][e];
        }
        if (s == e) {
            return nums[s] * (s > 0 ? nums[s - 1] : 1) *
                   (s < n - 1 ? nums[s + 1] : 1);
        }
        int m = 0;
        for (int i = s; i <= e; i++) {
            auto nexval = (e < n - 1 ? nums[e + 1] : 1);
            auto preval = (s >= 1 ? nums[s - 1] : 1);
            auto b = nums[i] * preval * nexval;
            auto fhalf = start(nums, s, i - 1);
            auto shalf = start(nums, i + 1, e);
            auto val = b + fhalf + shalf;
            m = max(m, val);
        }
        
        return dp[s][e] = m;
    }

public:
    int maxCoins(vector<int>& nums) { 
        memset(dp, -1, sizeof(dp));
        return start(nums, 0, nums.size() - 1); }
};
/**
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

we want to break the problem into subsets that we can easily sove.
If we say we want to solve(arr, 0, n-1). we can find the optimal value by
solving [0, k-1] and [k+1, n-1] but because these needs to be multiplied by k we solve for 
k being the last item to be selected in the range instead.
so we burst all [0, k-1] and [k+1, n-1] and then we burst k. For a more generical optimal substructure:
solve(s, e) = solve(s, k-1) + solve(k+1 , e) + val[k] * val[s-1] * val[e+1]
with val[i] = nums[i] if i < n and i > 0 else 1;
we can then memoise that substructure with dp[s][e] and it is order of e*s*(e-s+1) => O(N3). 
*/
