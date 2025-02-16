class Solution {
public:
    // O(N+M)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m1 = 0, m2 = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int pt1 = 0, pt2 = 0;
        while(pt1 + pt2 <= (n1+n2)/2) {
            m2 = m1;
            if (pt1 >= n1) {
                m1 = nums2[pt2++];
            } else if(pt2 >= n2) {
                m1 = nums1[pt1++];
            } else if (nums1[pt1] > nums2[pt2]) {
                m1 = nums2[pt2++];
            } else {
                m1 = nums1[pt1++];
            }
        }
        if ((n1+n2)%2) {
            return m1;
        } else {
            return (m1+m2)/2.;
        }
    }
    // O(LOG(N+M))
    // TODO
};
