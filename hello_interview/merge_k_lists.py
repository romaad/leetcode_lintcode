import heapq
from typing import List, Optional

# class ListNode:
#     def __init__(self, val: int = 0, next: 'ListNode' = None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeKLists(self, lists: List[Optional['ListNode']]) -> Optional['ListNode']:
        # Store (value, index, node) to avoid comparing ListNode objects when values tie
        items = [(l.val, i, l) for i, l in enumerate(lists) if l]
        heapq.heapify(items)
        
        dummy = ListNode(0)
        cur = dummy
        
        while items:
            v, i, node = heapq.heappop(items)
            cur.next = node
            cur = cur.next
            
            if node.next:
                heapq.heappush(items, (node.next.val, i, node.next))
                
        return dummy.next
