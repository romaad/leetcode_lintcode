/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        queue<TreeNode *> q;
        if(root)
            q.push(root);
        vector<vector<int>> res;
        
        while(!q.empty() ) {
            int cnt = q.size();
            vector<int> resSmall;
            while(cnt--) {
                TreeNode * t = q.front(); q.pop();
                resSmall.push_back(t->val);
                if(t->left) {
                    q.push(t->left);
                } 
                if(t->right) {
                    q.push(t->right);
                }
            }
            res.push_back(resSmall);
        }
        return res;
    }
};
