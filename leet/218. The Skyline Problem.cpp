using std::vector;
using std::priority_queue;
using std::pair;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& bs) {
        vector<pair<int,int>> xs;
        for (int i = 0 ; i < bs.size(); i++) {
            auto& b = bs[i];
            xs.push_back(make_pair(b[0], -b[2]));
            xs.push_back(make_pair(b[1], b[2]));
        }
        sort(xs.begin(), xs.end());
        multiset<int> pq{0};
        int cur_h = 0;
        vector<vector<int>> ans;
        for (int i = 0 ; i < xs.size() ; i++) {
            int x = xs[i].first;
            int h = xs[i].second;
            if(h < 0) {
                pq.insert(-h);
            } else {
                pq.erase(pq.find(h));
            }
            
            auto& top = *pq.rbegin();
            if(cur_h != top) {
                cur_h = top;
                ans.push_back({x, top});
            }
        }
        return ans;

    }
};
