class Solution {
private:
    vector<int> cnt;
public:
    string customSortString(string order, string str) {
        cnt.resize(26, 0);
        for(int i = 0 ;i < str.size() ; i++) {
            cnt[str[i] - 'a']++;
        }
        
        string out = "";
        for(int i  = 0 ; i < order.size() ; i++) {
            if(cnt[order[i]-'a']) {
                out += string(cnt[order[i]-'a'], order[i]);
            }
            cnt[order[i]-'a'] = 0;
        }
        for(int i = 0 ; i < cnt.size(); i++) {
            if(cnt[i]) {
                out += string(cnt[i], i+'a');
            }
        }
        return out;
    }
};
