class Solution {
private:
    int dp[50][50];
    int solve(vector<int>& v, int i, int j) {
        if (i == j - 1){
            return 0;
        }
        if (dp [i][j] != -1) { 
            return dp[i][j];
        }
        int m = -1;
        int t = v[i] * v[j];
        for (int k = i + 1 ; k < j; k++) {
            int val = t * v[k] + solve(v, k, j) +
                solve(v, i, k);
            if (m == -1) {
                m = val;
            } else {
                m = min(val, m);
            }
        }
        return dp[i][j] = m;
    }
public:
    int minScoreTriangulation(vector<int>& v) {
        memset(dp, -1, sizeof(dp));
        return solve(v, 0, v.size()-1);
    }
};
