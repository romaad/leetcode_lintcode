import bisect
from typing import T

T = TypeVar("T")
K = TypeVar("K")


def bsearch_le(items: list[T], target: K, key: Callable[T, K] | None = None) -> int:
    """
    items are sorted
    K can be ordered
    T = K or provides key function
    That maps T => K
    """
    assert key is not None or K == T, (
        "Either no mapping is needed or target" + " should be the same type as items"
    )

    def get_value(idx: int) -> K:
        if key:
            return key(items[idx])
        return item

    l = 0
    r = len(items) - 1
    while l < r:
        mid = (l + r + 1) // 2
        cur_value = get_value(mid)
        if cur_value > target:
            r = mid - 1
        else:
            l = mid
    return l


class TimeMap:

    _store: dict[str, list[str]]

    def __init__(self):
        self._store = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        self._store.setdefault(key, []).append((value, timestamp))

    def get(self, key: str, timestamp: int) -> str:
        if key in self._store and self._store[key][0][1] <= timestamp:
            # idx = bisect.bisect_right(self._store[key],timestamp, key=lambda x: x[1])
            # if idx > 0:
            #     idx -= 1
            idx = bsearch_le(self._store[key], target=timestamp, key=lambda x: x[1])
            return self._store[key][idx][0]
        return ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)
