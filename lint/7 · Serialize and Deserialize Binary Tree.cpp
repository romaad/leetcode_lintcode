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
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) {
        // write your code here
        if(root == NULL) {
            return "#";
        }
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        // write your code here
      //write and read in the same order
        if(data.size() == 0) {
            return NULL;
        }
        // cout<<data<<endl;
        TreeNode * val;
        int idx = data.find(",");
        if(idx == -1) idx = data.size();
        if(idx == 1 && data[0] == '#') {
            if(idx+1 < data.size())
                data = data.substr(idx+1);
            return NULL;
        }
        val = new TreeNode(stoi(data.substr(0, idx)));
        if(idx+1 < data.size())
            data = data.substr(idx+1);
        val->left = deserialize(data);
        val->right = deserialize(data);
        return val; 
    }
};
