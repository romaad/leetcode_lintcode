// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf destination buffer
     * @param n maximum number of characters to read
     * @return the number of characters read
     */
     queue<char> q;
    int read(char *buf, int n) {
        // Write your code here
        // why is this hard?
        int numOReads = (n-q.size()+3)/4;
        while(numOReads--){
            char bb[4];
            int len = read4(bb);
            int x = 0;
            while(x < len) {
                q.push(bb[x++]);
            }
            if(len < 4) break;
        }
        int retLen = min((int)q.size(), n);
        int x= retLen;
        while(x--) {
            *(buf) = q.front(); q.pop();
            buf++;
        }

        return retLen;

        
    }
};
