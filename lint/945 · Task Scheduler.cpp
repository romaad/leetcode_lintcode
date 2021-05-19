class Solution {
public:
    /**
     * @param tasks: the given char array representing tasks CPU need to do
     * @param n: the non-negative cooling interval
     * @return: the least number of intervals the CPU will take to finish all the given tasks
     */
    int leastInterval(string &tasks, int n) {
        // write your code here
        vector<int> v(26, 0);
        vector<char> maxV;
        int longest = 1;
        for(char c : tasks) { 
            v[c-'A']++;
            if(v[c-'A'] > longest){
                longest = v[c-'A'];
                maxV.clear();
                maxV.push_back(c);
            } else if(longest == v[c-'A']) {
                maxV.push_back(c);
            }
        }
        
        return max((longest-1) * (n+1) + maxV.size(), tasks.size());
    }
};
