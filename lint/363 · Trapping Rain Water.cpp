class Solution {
public:
    /**
     * @param heights: a list of integers
     * @return: a integer
     */
    int trapRainWater(vector<int> &heights) {
        // write your code here
        if(!heights.size()) return  0;
        int li = 0, ri = heights.size()-1, maxLeft = heights[li], maxRight = heights[ri], cnt = 0;
        while(li < ri){
            int left = heights[li], right = heights[ri];
            if(left > right){
                if(right > maxRight){
                    maxRight = right;
                }else{
                    cnt += -right + maxRight;
                }
                ri--;
            }else{
                if(left > maxLeft){
                    maxLeft = left;
                }else{
                    cnt += -left + maxLeft;
                }
                li++;
            }
        }
        return cnt;
    }
};
