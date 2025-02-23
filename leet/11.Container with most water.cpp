class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int maxVal = 0;
        while(l < r){
            int cur = min(height[l] , height[r]);
            maxVal = max(maxVal, cur * (r-l));
            if(cur == height[l]){
                l++;
            } else {
                r--;
            }
        }
        return maxVal;
    }
};
