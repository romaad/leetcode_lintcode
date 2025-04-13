class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int next = 2;
        for (int i  = next ; i < nums.size(); i++) {
          // because it is a sorted array, we can just check the last 2 elements by checking only one of them against the new element
            if (nums[i] != nums[next-2]) {
                nums[next] = nums[i];
                next++;
            }
        }
        return next;
    }
};
