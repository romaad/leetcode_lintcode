class Solution {
public:
    string minWindow(string s, string t) {
        int minSt = -1, minLen = -1;
        int st = 0, ed = 0;
        vector<int> mp(128, 0); // instead of a map overhead, create a vector idx
        int counter = t.size(); // number of remaining characters to be covered in the window
        for (int i =0 ; i < t.size() ; i++) {
            mp[t[i]]++; // map the number of characters occurence
        }
        while(ed < s.size()) {
            if(mp[s[ed++]]-- > 0) counter--; // if we cover a character that needs to be covered by the window, decrease counter
            while(counter == 0){ // if we are covering all needed chars, we can shorten the window from the begining
                if(ed - st < minLen || minLen == -1) {
                    // check if we are in the shortest window
                    minSt = st;
                    minLen = ed-st;
                }
                if (mp[s[st++]]++ == 0) {
                    // if the current character we removed will make the window invalid
                    // increase the window to mark it as so.
                    counter++;
                }
            }
        }
        if(minSt > -1) {
            return s.substr(minSt, minLen);
        }
        return "";
    }
};
