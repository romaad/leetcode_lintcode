class node {
    public:
    int height, col, row;
    node(int row, int col, int height) :height(height), col(col), row(row) {}
    bool operator<(const node& other) const {
        return height >= other.height;
    }

};
class Solution {
private:
vector<vector<bool>> visited;
int dircs[4][2] = {
    {0, 1},
    {1, 0},
    {0, -1},
    {-1, 0}
};
bool is_valid(int new_row, int new_col, int n, int m) {
    bool res = new_row < n && new_col < m && new_row >= 0 && new_col >= 0;
    // cout<<"res " << res << " for row=" << new_row << " and col=" << new_col << endl;
    return res;
}

public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() <= 0) {
            return 0;
        }
        int n = heightMap.size(), m = heightMap[0].size();
        priority_queue<node> pq;
        visited.resize(n,vector<bool>(m,false));
        int water = 0;
        for (int i =1 ;i < n -1; i++) {
            pq.push(node(i, 0, heightMap[i][0]));
            pq.push(node(i, m-1, heightMap[i][m-1]));
            visited[i][0] = visited[i][m-1] = true;
        }
        for (int i = 0 ; i< m; i++) {
            pq.push(node(0,i, heightMap[0][i]));
            pq.push(node(n-1,i, heightMap[n-1][i]));
            visited[0][i] = visited[n-1][i] = true;
        } 
        while (!pq.empty()) {
            auto front = pq.top(); pq.pop();
            // cout<< "P checking: " << front.height 
            // << "@" << front.row << "," << front.col<<endl;
            for (auto& dirc: dircs) {
                int new_row = front.row + dirc[0];
                int new_col = front.col + dirc[1];
                if(!is_valid(new_row, new_col, n, m)||visited[new_row][new_col]) {
                    continue;
                }
                auto& new_h = heightMap[new_row][new_col];
                // cout<< "checking: " << new_h 
                // << "@" << new_row << "," << new_col<<endl;

                if(new_h<front.height) {
                    water += front.height - new_h;
                    new_h = front.height;
                }
                pq.push(node(new_row, new_col, new_h));
                visited[new_row][new_col] = true;
                // cout << "water: " << water <<endl;
            }
        }
        return water;
    }
};
