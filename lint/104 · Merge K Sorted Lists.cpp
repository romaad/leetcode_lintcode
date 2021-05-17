class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *merge(ListNode * l1, ListNode * l2){
        if(!l1 && !l2) return NULL;
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode * head = NULL, * cur = NULL;
        while(l1 && l2) {
            if(cur){
                cur->next =  new ListNode(l1->val < l2->val ? l1->val : l2->val);
                cur = cur->next;
            }else{
                head = cur = new ListNode(min(l1->val, l2->val));
            }
            (l1->val < l2->val) ? (l1=l1->next):(l2 = l2->next);
        }
        ListNode * l = l1? l1 : l2;
        while(l){
            if(cur){
                cur->next = new ListNode(l->val);
                cur = cur->next;
            }else{
                head = cur = new ListNode(l->val);
            }
            l = l->next;
            
        }
        return head;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if(!lists.size()) return NULL;
        int i = 0, j = lists.size()-1;
        while(j != 0){
            int l = 0 , r = j;
            while(l < r){
               // cout<<l<<" : "<<r<<endl;
                lists[l] = merge(lists[l], lists[r]);
                l++;r--;
                if(l >= r) j = r;
            }
        }
        return lists[0];
    }
};
