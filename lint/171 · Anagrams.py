from typing import (
    List,
)
from collections import Counter, defaultdict

"""
A Goofy solution to anagrams, here we hash the characters using their value and not their position in the string.
We use a prime number for each character, and multiply them together to get a unique hash for each anagram group to avoid collisions.
This way, all anagrams will have the same hash value, allowing us to easily identify and group them together.
For example: abc = 2 * 3 * 5 = 30, and cba = 5 * 3 * 2 = 30, so they have the same hash value.
"""


def hash_f(s: str) -> int:
    summ = 0
    modd = 1e9+7
    h = defaultdict(lambda: 0)
    for c in s:
        val = ord(c) - ord('a') + 1
        summ += (31 ** (val * (h[val] + 1))) % modd
        summ %= modd
        h[val] += 1
    return summ

def hash2(s: str) -> int:
    # First 26 prime numbers corresponding to 'a' through 'z'
    primes = [
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 
        43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101
    ]
    modd = 10**9 + 7
    product = 1
    
    for c in s:
        # Map character to its prime representation
        prime_val = primes[ord(c) - ord('a')]
        product = (product * prime_val) % modd
        
    return product

class Solution:
    """
    @param strs: A list of strings
    @return: A list of strings
             we will sort your return value in output
    """
    def anagrams(self, strs: List[str]) -> List[str]:
        hashes = [hash2(s) for s in strs]
        cs = Counter(list(hashes))
        print(cs)
        print(hashes)
        ret = []
        for i in range(len(strs)):
            h = hashes[i]
            s = strs[i]
            if cs[h] > 1:
                ret.append(s)
        return ret