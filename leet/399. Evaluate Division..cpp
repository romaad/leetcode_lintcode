class Solution {
    // struct Edge {
    //     double 
    // }
        unordered_map<string, unordered_map<string, double>> g;
        // {a: {b: 5, c: 6}} - a/b = 5, a/c = 6

optional<double> dfs(string st, string tgt) {
    stack<pair<string, double>> stk;
    stk.push(make_pair(st, 1));
    unordered_set<string> vis;
    while(!stk.empty()){
        auto cur = stk.top(); stk.pop();
    if (g.find(cur.first) == g.end()){
        continue;
    }
        if(cur.first == tgt) {
            return cur.second;
        }
        if (vis.find(cur.first) != vis.end()) {
            continue;
        }
        vis.insert(cur.first);
        for(auto it = g[cur.first].begin(); it != g[cur.first].end() ; it++){
            stk.push(make_pair(it->first, it->second * cur.second));
        }
    }
    return nullopt;
}
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0 ; i < equations.size() ; i++) {
            auto &eq = equations[i];
            g[eq[0]][eq[1]] = values[i];
            g[eq[1]][eq[0]] = 1./values[i];
        }
        vector<double> res;
        for (int i = 0 ; i < queries.size(); i ++) { 
            string st = queries[i][0], ed = queries[i][1];
            auto val = dfs(st, ed);
            if (val == nullopt) {
                res.push_back(-1);
            } else {
                res.push_back(val.value());
            }

        }
        return res;
    }
};
