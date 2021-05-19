class Solution {
private:

    bool doubleCheck(string s, int l, int r) {
        while(l < r) {
            if(s[l++] != s[r--]) return false;
        }
        return true;
    }

public:
    /**
     * @param s: a string
     * @return: whether you can make s a palindrome by deleting at most one character
     */
    bool validPalindrome(string &s) {
        // Write your code here
        // actually solved this during a 10 mins in a phone screen
        // without seeing it before B)
        int l = 0, r = s.size()-1;
        while(l < r) {
            if(s[l] != s[r]) return doubleCheck(s, l, r-1) || doubleCheck(s, l+1, r);
            l++; r--;
        }
        return true;
    }
    
};
