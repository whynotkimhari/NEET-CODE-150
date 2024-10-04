class Solution:
    def maxScore(self, s: str) -> int:
        num1 = 0
        for c in s:
            if c == '1':
                num1 += 1

        num0l = 0
        num1l = 0

        res = 0
        for c in s[:-1]:
            if c == '0':
                num0l += 1
            else:
                num1l += 1
            
            res = max(res, num0l + num1 - num1l)

        return res