class Solution {
public:
    /**
     * @param a: a number
     * @param b: a number
     * @return: the result
     */
    string addBinary(string &a, string &b) {
        // write your code here
        int na = a.size(), nb = b.size();
        int minn = min(na,nb);
        string res = "";
        int carry = 0;
        for(int i = 0; i < minn; i++) {
            int ma = a[na-i-1] - '0';
            int mb = b[nb-i-1] - '0';
            int sum = (ma + mb + carry);
            carry = sum/2;
            res = to_string(sum%2) + res;
        }
        string rem = (minn == na? b : a);
        int maxn = max(na, nb);
        for(int i = minn; i < maxn || carry > 0; i++) {
            int sum = carry;
            if(i < maxn){
                int mm = rem[maxn-i-1] - '0';
                sum += mm;
            }
            carry = sum / 2;
            res = to_string(sum%2) + res;

        }
        // res = res.substr(res.find('1'));
        // no trailing zeros case apparently
        return res;


    }
};
