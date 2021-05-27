class Solution {
using graph = map<char, set<char>, greater <char>>;
private:
    set<char> visited;
    stack<char> st;    
    graph g;
    vector<char> tsort;
    
    string checkCycle()
    {
        unordered_map<char, int> pos;
        int ind = 0;
        string ret = "";
    
        while (!st.empty()) {
            pos[st.top()] = ind++;
            tsort.push_back(st.top());
            ret += st.top();    
            st.pop();
        }
    
        for (auto cur : g) {
            for (char x : cur.second) {
                if (pos[cur.first] > pos[x]) {
                    return "";
                }
            }
        }
        return ret;
    }

    void checkString(string x) {
        for(char xx : x) {
            if(g.find(xx) == g.end()) {
                g[xx] = set<char>();
            }
        }
    }

    char getDiff(string a, string b) {
        checkString(a);
        checkString(b);
        for(int i = 0 ; i < min(a.size(), b.size()); i++) {
            if(a[i] != b[i]) return i;
        }
        return -1;
    }

    bool compare(string a, string b) {
        int diff = getDiff(a, b);
        if(diff == -1) return a.size() < b.size();
        char x1 = a[diff], x2 = b[diff];
        g[x1].insert(x2);
        return true;
    }

    void dfs(char cur) {
        visited.insert(cur);
        if (g.find(cur) != g.end()){
            for(char x : g[cur]) {
                if(visited.find(x) == visited.end()) {
                    dfs(x);
                }
            }
        }
        st.push(cur);
    }
public:
    /**
     * @param words: a list of words
     * @return: a string which is correct order
     */
    string alienOrder(vector<string> &words) {
        // Write your code here
        // for(int i = 0; i < words.size(); i++) {
        //     for(int j = i +1; j < words.size(); j++) {
        //         compare(words[i], words[j]);
        //     }
        // }

        for(int i =0 ; i < words.size() - 1 ; i++) {
            if(!compare(words[i], words[i+1])) return "";//["abc", "ab"] is invalid somehow :D
        }

        for(auto fs : g) {
            if(visited.find(fs.first)==visited.end()){
                dfs(fs.first);
            }
        }

        return checkCycle();
        

    }
};
