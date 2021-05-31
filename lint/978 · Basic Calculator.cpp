class Solution {
private:
    stack <char> op;
    stack <int> nums;
    bool isnum = false;
    int curNum = 0;
    void doMath() {
        if(op.empty() || nums.size() < 2) return;
        char op1 = op.top(); op.pop();

        int num1 = nums.top(); nums.pop();
        int num2 = nums.top(); nums.pop();
        int num = 0;
        // cout<<num1<<":"<<num2<<":"<<op1<<endl;
        switch(op1) {
            case '+' :
                num = num1 + num2;
                break;
            case '-':
                num = num2 - num1;
                break;
        }
        nums.push(num);        
    }
    bool isNum(char x) {
        return x<= '9' && x>= '0';
    }

    void evalNum() {
        if(isnum) {
                isnum = false;
                nums.push(curNum);
                curNum = 0;
        }
    }
public:
    /**
     * @param s: the given expression
     * @return: the result of expression
     */
    int calculate(string &s) {
        // Write your code here
        // got this in an interview before and I don't remember writing all of this :D
        for(int i = 0 ; i < s.size(); i++) {
            if(isNum(s[i])) {
                isnum = true;
                curNum *= 10;
                curNum += s[i] - '0';
            } else if(s[i] == '+' || s[i] == '-' || s[i] == '(') {
                evalNum();
                if(s[i] == '+' || s[i] == '-') {
                    while (!op.empty() && op.top() != '(') {
                        doMath();
                    }
                }
                op.push(s[i]);
            } else if(s[i] == ')') {
                evalNum();
                while(!op.empty() && op.top() != '(') {
                    doMath();
                }
                if(!op.empty()) op.pop();
            }
        }
        if(isnum) {
            nums.push(curNum);
        }
        while(!op.empty() && nums.size() > 1) {
            doMath();
        }
        if(nums.size() > 1 || !op.empty()) return -1;
        return nums.top(); 
    }
};
