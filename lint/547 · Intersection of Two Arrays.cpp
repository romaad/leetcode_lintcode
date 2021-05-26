class Solution {
public:
    /**
     * @param nums1: an integer array
     * @param nums2: an integer array
     * @return: an integer array
     */
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        // write your code here
        set<int> s;
        for(int num : nums1) {
            s.insert(num);
        }
        set<int> ret;
        for(int num : nums2) {
            if(s.find(num) != s.end()) {
                ret.insert(num);
            }
        }
        return vector<int>(ret.begin(), ret.end());
    }
};
