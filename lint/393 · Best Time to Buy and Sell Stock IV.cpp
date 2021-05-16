class Solution {
public:
    /**
     * @param K: An integer
     * @param prices: An integer array
     * @return: Maximum profit
     */
    int maxProfit(int k, vector<int> &prices) {
        // write your code here
        int n = prices.size();
        if(!n) return 0;
        //if k>n/2 it means you can trade as much as you can.
        if(k > n/2) {
            int maxProf = 0;
            for(int i = 1 ; i < n; i++) {
                maxProf += max(0, prices[i]-prices[i-1]);
            }
            return maxProf;
        }
        
        // prof[i][j] = profit at day i after doing j transactions
        // prof[i][j] = max(prof[i-1][j-1], prices[i]-prices[l] + prof[l][j-1] for all l < i)
        
        vector<vector<int>> prof(n, vector<int> (k+1, 0));

        //from g4g
        // for (int j = 1; j <= k; j++) {
        //     for (int i = 1; i < n; i++) {
        //         int maxP = -1;
    
        //         for (int l = 0; l < i; l++)
        //             maxP = max(maxP,
        //                             prices[i] - prices[l] + prof[l][j - 1]);
    
        //         prof[i][j] = max(prof[i-1][j], maxP);
        //     }
        // }
        // return prof[n-1][k];

        //this however can be optimised
        //maxp can be tracked from the previous element directly


        for (int j = 1; j <=k ; j++) {
            int maxP = -prices[0];
            for(int i = 1; i < n ; i++) {
                maxP = max(maxP, prof[i-1][j-1]- prices[i-1]);
                prof[i][j] = max(prof[i-1][j], prices[i] + maxP); 
            }
        }
        return prof[n-1][k];
    }
};
