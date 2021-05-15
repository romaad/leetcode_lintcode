class Solution {
public:
    /**
     * @param a: A number
     * @return: Returns the maximum number after insertion
     */
    int InsertFive(int a) {
        // write your code here
        bool sign = (a < 0);
        bool dirt = false;
        string x = to_string(a > 0 ? a : -a);
        for(int i =0 ; i < x.size() ; i++) {
            if( (x[i] > '5' && sign) || ( x[i] < '5' && !sign)) {
                x = (sign? "-" : "") + (i> 0 ? x.substr(0, i) : "") + "5" + x.substr(i);
                dirt = true;
                break;
            }
        }
        return stoi((dirt? x : (sign? "-" + x + "5" : "5" + x ))); 
    }
};
