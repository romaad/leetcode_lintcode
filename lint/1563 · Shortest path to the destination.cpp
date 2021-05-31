    vector<vector<int>> dirs {
        {0,1}, {1, 0}, {-1, 0}, {0, -1}
    };

class Solution {
private:
    int n, m;
    class node {
        public:
        int x, y;
    };

    bool validate(vector<vector<int>> &targetMap, int x, int y) {
        return x < n && y < m && x > -1 && y > -1 &&
        targetMap[x][y] != 1;
    }
public:
    /**
     * @param targetMap: 
     * @return: nothing
     */
    int shortestPath(vector<vector<int>> &targetMap) {
        // Write your code here
        n = targetMap.size();
        if(!n) return -1;
        m = targetMap[0].size();
        if(!m) return -1;

        queue<node> q;
        q.push({0, 0});
        int levCnt = 0;
        while(!q.empty()) {
            int limit = q.size();
            while(limit --) {
                node n = q.front(); q.pop();
                if(targetMap[n.x][n.y] == 2) return levCnt;
                targetMap[n.x][n.y] = 1;
                for(vector<int> dir : dirs) {
                    if(validate(targetMap, n.x+dir[0] , n.y+dir[1])) {
                        q.push({n.x + dir[0] , n.y + dir[1]});
                    }
                }
            }
            levCnt ++;
        }
        return -1;
    }
};
