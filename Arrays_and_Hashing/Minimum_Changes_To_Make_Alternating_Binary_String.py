class Solution:
    def minOperations(self, s: str) -> int:
        diff1, diff2 = 0, 0
        
        for i in range(len(s)):
            if s[i] != f'{i % 2}':
                diff1 += 1
            else:
                diff2 += 1
                
        return min(diff1, diff2)