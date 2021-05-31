class Solution {
private: 
    unordered_map<char ,int> targetcnt;
    unordered_map<char ,int> sourcecnt;
    bool compare() {
        for(auto item : targetcnt) {
            if(item.second > sourcecnt [item.first]) {
                return false;
            }
        }
        return true;
    }
public:
    /**
     * @param source : A string
     * @param target: A string
     * @return: A string denote the minimum window, return "" if there is no such a string
     */
    string minWindow(string &source , string &target) {
        // write your code here
        for(char c : target) {
            targetcnt[c]++;
        }
        int n = source.size();
        int l = 0;
        int r = -1;
        int resl = -1, resr = -1;
        while(l < n && r < n) {
            while(r < n-1 && !compare()) {
                sourcecnt[source[++r]]++;
            }
            if(!compare()) break;
            while(l <= r && compare()) {
                if(r-l < resr - resl || (resr == -1 && resl == -1)) {
                    // cout<<resr<<":"<<resl<<endl;
                    resr = r; resl = l;
                }
                sourcecnt[source[l++]]--;
            }
        }
        if(resr == resl && resl == -1) return "";
        return source.substr(resl, resr-resl+1);
    }
};
