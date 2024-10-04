class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        d = {}
        for c in chars:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
        z = dict(d)
        res = 0
        for word in words:
            ok = True
            for c in word:
                if c in d:
                    d[c] -= 1

                    if d[c] < 0:
                        ok = False
                        break
                else:
                    ok = False
                    break
            
            if ok:
                res += len(word)
            d = dict(z)
            
        return res