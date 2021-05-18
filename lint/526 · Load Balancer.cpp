class LoadBalancer {
private:
    vector<int> v;
    unordered_map<int, int> mp;
public:
    LoadBalancer() {
        // do intialization if necessary
    }

    /*
     * @param server_id: add a new server to the cluster
     * @return: nothing
     */
    void add(int server_id) {
        // write your code here
        mp[server_id] = v.size();
        v.push_back(server_id);

    }

    /*
     * @param server_id: server_id remove a bad server from the cluster
     * @return: nothing
     */
    void remove(int server_id) {
        // write your code here
        int idx = mp[server_id];
        v[idx] = v[v.size()-1];
        mp[v[idx]] = idx;
        mp.erase(server_id);
        v.erase(v.end()-1);
    }

    /*
     * @return: pick a server in the cluster randomly with equal probability
     */
    int pick() {
        // write your code here
        int rn = rand() % v.size();
        return v[rn];
    }
};
