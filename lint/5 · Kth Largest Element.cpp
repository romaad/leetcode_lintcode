class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
    int kthLargestElement(int k, vector<int> &nums) {
        // write your code here
        if(k > nums.size()) return 0;
        return findInd(nums.size() - k, nums, 0, nums.size()-1);
    }
    void swap(vector<int> & v, int i , int j) { 
        if( i == j) return;
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    int findInd(int ind, vector<int>& nums, int st, int ed) {
//         int pivot = st + rand() % (ed-st+1);
//         swap(nums, pivot, ed); //actually randomisation sucks in this question for some reason
        int j = st;
        for(int i = st; i < ed; i++) {
            if(nums[i] < nums[ed]) {
                swap(nums, i, j++);
            }
        }
        swap(nums, ed, j);
        if(j == ind) return nums[j];
        if(j > ind) return findInd(ind, nums, st, j-1);
        return findInd(ind, nums, j + 1, ed);
    }
};
