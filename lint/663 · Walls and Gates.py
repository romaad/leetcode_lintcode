from typing import (
    List, Union
)
from collections import deque
INF = (1<<31)-1

dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

def gnbr(cur: tuple[int, int], d: tuple[int, int], n: int, m: int) -> Union[tuple[int, int],None]:
    dy,dx = d
    cy, cx = cur
    ny= cy+dy
    nx= cx+dx
    if (ny >= 0 and nx >= 0 and ny < n and nx < m):
        return (ny, nx)
    return None
# you can either call this for each 0 room O(k*n*m) = O((nm)^2)
def bfs(g: list[list[int]], row: int, col: int, n: int, m: int):
    q = deque([(row, col)])
    vis = set()
    while len(q) > 0:
        cur = q.popleft()
        if cur in vis:
            continue
        vis.add(cur)
        curVal = g[cur[0]][cur[1]]
        for d in dirs:
            if(nbr := gnbr(cur, d, n, m)):
                if g[nbr[0]][nbr[1]] < 1:
                    continue
                g[nbr[0]][nbr[1]] = min(g[nbr[0]][ nbr[1]], curVal+1)
                q.append(nbr)

# optimisation of multi-source BFS where we load the queue with all the 0 rooms
# this will allow us to not repeat the revists of the cells from other sources
def msbfs(g: list[list[int]],n: int, m: int, ids: list[tuple[int, int]]):
    q = deque(ids)
    while q:
        cur = q.popleft()
        curVal = g[cur[0]][cur[1]]
        for d in dirs:
            if(nbr := gnbr(cur, d, n, m)):
                if g[nbr[0]][ nbr[1]] == INF:
                    g[nbr[0]][ nbr[1]] = curVal+1
                    q.append(nbr)
class Solution:
    """
    You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 2^31 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a Gate, that room should remain filled with INF
Example
Example1
```
Input:
[[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
Output:
[[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]

Explanation:
the 2D grid is:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
the answer is:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
```
Example2
```
Input:
[[0,-1],[2147483647,2147483647]]
Output:
[[0,-1],[1,2]]
```
    """
    """
    Soln:
    Multi-source BFS, we load all the 0 rooms into the BFS queue, when we reach a room
    if it is not INF we skip it as it is guaranteed by BFS that it is already filled with the shortest distance to a gate,
    if it is INF we fill it with the current distance + 1 and add it to the queue.
    O(n*m) time and space complexity, as we visit each cell at most once and store them in the queue at most once.
    """
    def walls_and_gates(self, rooms: List[List[int]]):
        n = len(rooms)
        m = len(rooms[0])
        ids = [(r,c) for r in range(n) for c in range(m) if rooms[r][c] == 0]
        msbfs(rooms, n, m, ids)
        # Slower: O(k*n*m) where k is the number of gates, as we do BFS from each gate
        """
        for r in range(n):
            for c in range(m):
                if rooms[r][c] == 0:
                    bfs(rooms, r, c, n, m)
        """
        