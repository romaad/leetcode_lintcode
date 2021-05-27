class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        set<int> isValid;
        for(int i = 0; i < s.size() ; i++) {
            if(s[i] ==')') {
                if(!st.empty()) {
                    isValid.insert(i);
                    isValid.insert(st.top());
                    st.pop();
                }
            } else if(s[i] == '(') {
                st.push(i);
            }
        }
        string res = "";
        for(int i =0 ; i < s.size() ;i++){
            if(s[i] != '(' && s[i] != ')') {
                res += s[i];
            }else {
                if(isValid.find(i) != isValid.end()){
                    res += s[i];
                }
                
            }
        }
        return res;
        
    }
    
};
