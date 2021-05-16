class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        // deceiving :D 
        int prof = 0;
        for(int i = 1 ; i < prices.size() ; i++) {
            if(prices[i] > prices[i-1])
                prof += prices[i] - prices[i-1];
        }
        return prof;
    }
};
