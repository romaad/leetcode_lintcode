/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param node: a list node in the list
     * @param x: An integer
     * @return: the inserted new list node
     */
    ListNode * insert(ListNode * node, int x) {
        // write your code here
        ListNode * cur = node;
        ListNode * nn = new ListNode(x);
        if(!cur) return nn;
        while(cur->next != NULL && cur->next != node) {
            // if() {
                if( (cur->val < x && cur->next->val >= x) || 
                    (cur->val < x && cur->next->val < cur->val) ||
                    (cur->val > cur->next->val  && cur->next->val >= x)
                ) {
                    nn->next = cur->next;
                    cur->next = nn;
                    break;
                } else {
                    cur = cur->next;
                }
            // }
        }
        cur->next = nn;
        return node;
    }
};
