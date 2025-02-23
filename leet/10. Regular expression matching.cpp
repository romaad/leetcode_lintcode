class Solution {
private:
    vector<vector<int>> dp;
    bool solve(string& s, string& p, int is, int ip) {
        if (dp[is][ip] != -1)
            return bool(dp[is][ip]);
        if (is == s.size() && ip == p.size()) {
            return true;
        }
        bool curMatch = is < s.size() && (s[is] == p[ip] || p[ip] == '.');
        if (ip < p.size() - 1 && p[ip + 1] == '*') {
            return dp[is][ip] = (curMatch && (solve(s, p, is + 1, ip)) ||
                                 solve(s, p, is, ip + 2));
        } else {
            return dp[is][ip] = curMatch && solve(s, p, is + 1, ip + 1);
        }
    }

public:
    bool isMatch(string s, string p) {
        dp = vector(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(s, p, 0, 0);
    }
};
