from collections import deque



"""
2 ideas here, first undirected tree means you can consider any node to be the root.
Second if we sum all the subtree under a node and that subtree is divisible by k, then we can split it from the tree.
That's because it is guaranteed that the tree sum is divisible by k.
"""
class Solution:
    def maxKDivisibleComponents(self, n: int, edges: List[List[int]], values: List[int], k: int) -> int:
        count = 0
        edge_mp = {}
        vis = set()
        parents = {}
        for a,b in edges:
            edge_mp.setdefault(a, set()).add(b)
            edge_mp.setdefault(b, set()).add(a)
        root = 0
        def dfs(node: int) -> int:
            nonlocal count
            val = values[node]
            vis.add(node)
            for c in edge_mp.get(node, []):
                if c in vis:
                    continue
                val += dfs(c)
                val %= k
            if val %k==0:
                count += 1
            # print(f"dfs({node})={val}")
            return val
        dfs(0)
        return count
        
