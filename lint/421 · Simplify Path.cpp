class Solution {
public:
    /**
     * @param path: the original path
     * @return: the simplified path
     */
    string simplifyPath(string &path) {
        // write your code here
        
        int level = 0;
        string cur = path;
        stack<string> st;
        while(cur.size()) {
            int ind = cur.find('/');
            string path = (ind > 0 ? cur.substr(0, ind) : cur);
            if(ind != 0) {
                if(path == "..") {
                    if(!st.empty()) {
                        st.pop();
                    }
                } else if (path != ".") {
                    st.push(path);
                }
            }
            if(ind == -1) break;
            cur = cur.substr(ind+1);
            // cout<<cur<<ind+1<<path<<endl;
        }
        string out = "";
        while(!st.empty()) {
            out = "/" + st.top() + out;
            st.pop();
        }
        return out.size() ? out : "/";
        
    }
};
