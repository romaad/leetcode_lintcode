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
#define ll long long
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode * root) {
        // write your code here
        // if(!root) return true;
        return validate(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }

    bool validate(TreeNode * root, ll minVal, ll maxVal) {
        if(root) {
            return (ll)root->val > minVal && (ll)root->val < maxVal &&
                validate(root->left, minVal, root->val) &&
                validate(root->right, root->val, maxVal);
        }
        return true;
    }
};
