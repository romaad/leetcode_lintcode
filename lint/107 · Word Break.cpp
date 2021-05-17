class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    vector<int> dp;
    int maxCnt = 0;
    string s; unordered_set<string> dict;
    bool wordBreak(string &s, unordered_set<string> &dict){
        // write your code here
        this->dict = dict;
        this->s = s;
        for(auto it : dict){
            maxCnt = max(maxCnt,(int)it.length());
        }
        dp = vector<int>(s.size(), -1);
        return core(0);
    }
    
    bool core(int ind){
        if(ind >= s.size()) return true;
        if(dp[ind]!=-1)return dp[ind];
        bool flag = false;
        for(int i = ind ; i < s.length() && i - ind < maxCnt;i++){
            string left = s.substr(ind,i-ind+1);
            if(dict.find(left)!=dict.end()){
                flag |= core(i+1);
              if(flag) break;
            }
        }
        return dp[ind] = flag;
    }
};
