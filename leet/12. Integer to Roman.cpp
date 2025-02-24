class Solution {
public:
    string intToRoman(int num) {
        const int SZ = 13;
        pair<int, string> mp [SZ] = {
            {1, "I"},
            {4, "IV"},
            {5, "V"},
            {9, "IX"},
            {10, "X"},
            {40, "XL"},
            {50, "L"},
            {90, "XC"},
            {100, "C"},
            {400, "CD"},
            {500, "D"},
            {900, "CM"},
            {1000, "M"},
        };
        stringstream out;
        while (num) {
            for (int i = SZ-1; i>=0; i--) {
                if (num >= mp[i].first){
                    int val = num/mp[i].first;
                    num = num%mp[i].first;
                    // cout<<num<< " "<<val<< mp[i].second<<endl;
                    for(int j = 0; j < val ; j++) {
                        out<<mp[i].second;
                    }
                } 
            }
        }
        return out.str();
    }
};
