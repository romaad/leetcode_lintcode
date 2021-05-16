class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        if(!prices.size()) return 0;
        int minSofar = prices[0], maxProf = 0;
        for(int price : prices) {
            minSofar = min(minSofar, price);
            maxProf = max(maxProf, price-minSofar);
        }
        return maxProf;
    }
};
