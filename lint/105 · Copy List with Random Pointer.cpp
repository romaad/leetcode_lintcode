/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here
        //O(N) T + O(1) M
        using N = RandomListNode;
        N * start = head;
        while(start) {
            N * nn = new N (start->label);
            nn->next = start->next;
            start->next = nn;
            start = nn->next;
        }
        start = head;
        N * ret = start? start->next : NULL;
        while(start) {
            N * nn = start->next;
            nn->random = (start->random? start->random->next : NULL);
            start = nn->next;
        }
        start = head;
        while(start) {
            N * nn = start->next;
            if(nn){
                start->next = nn->next;
            }
            start = nn;
        }
        return ret;
    }
};
