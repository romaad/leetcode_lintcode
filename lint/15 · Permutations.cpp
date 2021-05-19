class Solution {
public:
    /*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int>> permute(vector<int> &nums) {
        // write your code here
      // idk the iterative sol lol
        return start(nums, 0);
    }

    vector<vector<int>> start(vector<int> nums, int bitMask) {
        if(bitMask == ((1<<nums.size())-1))
            return vector<vector<int>>(1, vector<int>());
        vector<vector<int> > res;
        for(int i = 0 ; i < nums.size() ; i++) {
            if(!((1<<i) & bitMask)) {
                auto v = start(nums, bitMask | (1<<i));
                for(auto vv : v) {
                    vv.push_back(nums[i]);
                    res.push_back(vv);
                }
            }
        }
        return res;
    }
};
