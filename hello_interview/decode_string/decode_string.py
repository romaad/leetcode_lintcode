"""
Solution for https://www.hellointerview.com/learn/code/stack/decode-string
"""


def readchars(s: str, start: int) -> tuple[str, int]:
    i = start
    while i < len(s) and s[i].isalpha():
        i += 1
    return s[start:i], i


def readints(s: str, start: int) -> tuple[int | None, int]:
    if start == len(s):
        return None, start

    i = start

    while i < len(s) and s[i].isdigit():
        i += 1
    if not s[start].isdigit():
        return None, i
    return int(s[start:i]), i


def decode(s: str, i: int) -> tuple[str, int]:
    if i == len(s):
        return "", i
    chars, i = readchars(s, i)
    k, i = readints(s, i)
    if k:
        assert s[i] == "["
        res, i = decode(s, i + 1)
        assert s[i] == "]"
        i += 1
        chars += k * res
    return chars, i


def decode_string(s: str) -> str:
    """
    Given an encoded string, return its decoded string.

    The encoding rule is: k[encoded_string], where the encoded_string
    inside the square brackets is being repeated exactly k times.

    Example:
    s = "3[a]2[bc]" -> "aaabcbc"
    s = "3[a2[c]]" -> "accaccacc"
    """
    # Your code goes here
    ret = ""
    i = 0
    while i < len(s):
        res, i = decode(s, i)
        ret += res
    return ret
