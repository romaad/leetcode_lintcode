class Solution:

    def justify(self, tp: tuple[int, list[str]], islast : bool, maxWidth: int) -> str:
        ret = ""
        cnt, words = tp
        
        space_cnt = (maxWidth - cnt) // (len(words) - 1) if len(words) > 1 else 0
        remainder = (maxWidth - cnt) % (len(words) - 1) if len(words) > 1 else 0
        for word in words:
            if ret and not islast:
                ret += ' ' * (space_cnt + (1 if remainder > 0 else 0) + 1)
                remainder -= 1
            elif ret:
                ret += ' '
            ret += word
        return ret + (maxWidth - len(ret)) * ' '

    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ret: list[tuple[int, list[str]]] = [(0, [])]
        cur = -1
        for word in words:
            if len(word) + cur + 1 > maxWidth:
                ret[-1]= (cur, ret[-1][1])
                ret.append((0, []))
                cur = -1
            ret[-1][1].append(word)
            cur += len(word) + 1 #space
        
        return [self.justify(tp, i==len(ret) -1, maxWidth) for i, tp in enumerate(ret)]
