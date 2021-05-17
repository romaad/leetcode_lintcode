class Solution {
private:
    vector<vector<int>> dp;
    bool start(string s, string p, int is, int ip) {
        if(ip < p.size()) {
            if(dp[is][ip] > -1) {
                return dp[is][ip];
            }
            bool matchChar = is < s.size() && (s[is] == p[ip] || p[ip] == '.');
            bool ret;
            if(ip < p.size() - 1 && p[ip+1] == '*') {
                ret =  (matchChar && start(s,p, is+1, ip)) ||
                    start(s,p, is, ip+2);
            } else {
                ret = matchChar && start(s,p, is+1, ip+1); 
            }
            return dp[is][ip] = ret;
            
        }else if(is == s.size() && ip == p.size()) {
            return true;
        }
        return false;
        
    }
public:
    bool isMatch(string s, string p) {
        //spoiller alert, NFA won't work :D you need full regex->nfa->dfa :(
        //bottom up requires going from the left :(
        //doing normal recursion, no more fancy stuff
        dp = vector(s.size()+1, vector<int>(p.size()+1, -1));
        return start(s,p, 0, 0);
    }
    
};
