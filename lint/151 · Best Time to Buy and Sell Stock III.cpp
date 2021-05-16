class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        // write your code here
        // I call this unleash the pointers
        if(!prices.size()) return 0;
        int min1 = prices[0], prof1 = 0, min2 = prices[0], prof2 = 0;
        for(int price: prices){
            min1 = min(price, min1);
            prof1 = max(prof1, price-min1);
            min2 = min(min2, price - prof1);
            prof2 = max(prof2, price - min2);
        }
        return prof2;
    }
};
