class Node:
    val: int
    key: int
    next: 'Node|None'
    prev: 'Node|None'
    def __init__(self, val: int, key: int) -> None:
        self.val = val
        self.key = key
        self.next = self.prev = None

class DLL:
    tail: 'Node | None'
    head: 'Node | None'
    sz: int
    def __init__(self) -> None:
        self.head = self.tail = None
        self.sz = 0
    
    def add(self, val: int, key: int) -> Node:
        if not self.tail:
            self.head = self.tail = Node(val, key)
        else:
            self.tail.next = Node(val, key)
            self.tail.next.prev = self.tail
            self.tail = self.tail.next
        self.sz += 1
        return self.tail
    
    def add_node(self, n: Node) -> None:
        if not self.tail:
            self.head = self.tail = n
        else:
            self.head.prev = n
            n.next = self.head
            self.head = n
        self.sz += 1

    def remove(self, n: Node) -> None:
        if n == self.head:
            self.head = self.head.next
        if n == self.tail:
            self.tail = self.tail.prev
        if n.next:
            n.next.prev = n.prev
        if n.prev:
            n.prev.next = n.next
        n.next = n.prev = None
        self.sz -= 1
    
    def bubble(self, n: Node, rm: bool) -> None:
        if rm:
            self.remove(n)
        self.add_node(n)

    def remove_tail(self) -> Node:
        t = self.tail
        self.remove(self.tail)
        return t
    def print(self) -> None:
        return
        cur = self.head
        ret = ""
        while(cur):
            ret +=  " " + str(cur.val)
            cur = cur.next
        print(ret)
class LRUCache:
    """
    @param: capacity: An integer
    """
    _store: DLL
    _map: dict[int, Node]
    capacity: int
    def __init__(self, capacity: int):
        # do intialization if necessary
        self._store = DLL()
        self._map = {}
        self.capacity = capacity
    """
    @param: key: An integer
    @return: An integer
    """
    def get(self, key: int) -> int:
        # write your code here
        if key in self._map:
            n = self._bump_key(key)
            return n.val
        return -1 
    """
    @param: key: An integer
    @param: value: An integer
    @return: nothing
    """
    def set(self, key: int, value: int) -> None:
        # write your code here
        self._bump_key(key, value)
    
    def _bump_key(self, key: int, val: 'int|None' = None) -> Node:
        if key not in self._map and not val:
            raise Exception("shouldn't happen")
        exists = key in self._map
        if exists:
            n = self._map[key]
            if val:
                n.val = val
        else:
            if self._store.sz >= self.capacity:
                t = self._store.remove_tail()
                del self._map[t.key]
            n = Node(val, key)
            self._map[key] = n

        self._store.print()
        self._store.bubble(n, exists)
        self._store.print()

        return n
