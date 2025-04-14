class RandomizedSet {
private:
unordered_map<int,int> numToIndx;
        vector<int> vals;
public:
    RandomizedSet() : numToIndx({}), vals({}){
        std::srand(std::time({})); 
    }
    
    bool insert(int val) {
        if (numToIndx.find(val) != numToIndx.end()) {
            return false;
        }
        numToIndx[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (numToIndx.find(val) == numToIndx.end()) {
            return false;
        }
        int idx = numToIndx[val];
        auto last = vals[vals.size()-1];
        vals[idx] = last;
        numToIndx[last] = idx;
        vals.pop_back();
        numToIndx.erase(val);
        return true;
    }
    
    int getRandom() {
        int randIdx = rand() % vals.size();
        return vals[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
