class Solution {
private:
    string getSorted(string x) {
        sort(x.begin(), x.end());
        return x;
    }
public:
    /**
     * @param strs: A list of strings
     * @return: A list of strings
     */
    vector<string> anagrams(vector<string> &strs) {
        // write your code here
        unordered_map <string, vector<string>> mp;

        for(string x: strs) {
            string sx = getSorted(x);
            if(mp.find(sx) == mp.end() ){
                vector<string> v;
                v.push_back(x);
                mp[sx] = v;
            }else {
                mp[sx].push_back(x);
            }
        }

        vector<string> res;
        for(auto it: mp) {
            if(it.second.size() > 1) {
                for(string x : it.second) {
                    res.push_back(x);
                }
            }
        }
        return res;

    }
};
